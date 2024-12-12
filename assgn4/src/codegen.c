#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "tree.h"
#include "strtab.h"
#include "parser.tab.h"

#define MAX_REGISTERS 8

// Global variables
static int label_count = 0;
static int reg_count = 0;
static char current_scope[256] = "";

// Error flags
int has_multiply_declared_var = 0;
int has_multiply_declared_func = 0;
int has_undeclared_var = 0;
int has_undeclared_func = 0;
int has_function_mismatch = 0;
/*
const char* getNodeKindName(int kind) {
    switch (kind) {
        case PROGRAM: return "PROGRAM";
        case DECLLIST: return "DECLLIST";
        case DECL: return "DECL";
        case VARDECL: return "VARDECL";
        case TYPESPEC: return "TYPESPEC";
        case ASSIGNSTMT: return "ASSIGNSTMT";
        case IFSTMT: return "IFSTMT";
        case LOOPSTMT: return "LOOPSTMT";
        case RETURNSTMT: return "RETURNSTMT";
        case EXPR: return "EXPR";
        case FUNCCALL: return "FUNCCALL";
        case ARGLIST: return "ARGLIST";
        case INTEGER: return "INTEGER";
        case IDENTIFIER: return "IDENTIFIER";
        case RELOP_NODE: return "RELOP_NODE";
        case FUNDECL: return "FUNDECL";
        case ARRAY_ACCESS: return "ARRAY_ACCESS";
        case CONDSTMT: return "CONDSTMT";
        case WHILESTMT: return "WHILESTMT";
        case COMPOUNDSTMT: return "COMPOUNDSTMT";
        case FORMALDECLLIST: return "FORMALDECLLIST";
        case FORMALDECL: return "FORMALDECL";
        case TYPE_NODE: return "TYPE_NODE";
        case STMTLIST: return "STMTLIST";
        case EXPRESSION: return "EXPRESSION";
        case ADDEXPR: return "ADDEXPR";
        case SUBEXPR: return "SUBEXPR";
        case TERM: return "TERM";
        case FACTOR: return "FACTOR";
        case ADDOP_NODE: return "ADDOP_NODE";
        case SUBOP_NODE: return "SUBOP_NODE";
        case MULOP_NODE: return "MULOP_NODE";
        case DIVOP_NODE: return "DIVOP_NODE";
        case LT_NODE: return "LT_NODE";
        case GT_NODE: return "GT_NODE";
        case EQ_NODE: return "EQ_NODE";
        case NEQ_NODE: return "NEQ_NODE";
        case LTE_NODE: return "LTE_NODE";
        case GTE_NODE: return "GTE_NODE";
        case CHAR_NODE: return "CHAR_NODE";
        case ERROR_NODE: return "ERROR_NODE";
        case ARRAY_NODE: return "ARRAY_NODE";
        // ... add any other missing node kinds
        default: return "UNKNOWN_NODE_KIND";
    }
}
*/
// Helper functions
// Add near the top with your other helper functions
static int get_local_var_offset(const char* varname) {
    int offset = 4;  // Start after frame pointer
    
    // Look for local variables in current scope
    for (int i = 0; i < MAXIDS; i++) {
        if (strTable[i].id && 
            strcmp(strTable[i].scope, current_scope) == 0) {
            if (strcmp(strTable[i].id, varname) == 0) {
                return offset;
            }
            offset += 4;  // Each variable takes 4 bytes
        }
    }
    
    return -1;  // Variable not found
}

static int get_next_reg() {
    int reg = reg_count++;
    if (reg_count >= MAX_REGISTERS) {
        reg_count = 0;
    }
    return (reg < MAX_REGISTERS) ? reg : 0;
}

static int handle_comparison(tree* node, int reg1, int reg2, const char* op) {
    int result_reg = get_next_reg();
    printf("\t# Comparison operation (%s)\n", op);

    if (strcmp(op, "LT") == 0) {
        printf("\tslt $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    } else if (strcmp(op, "GT") == 0) {
        printf("\tslt $s%d, $s%d, $s%d\n", result_reg, reg2, reg1);
    } else if (strcmp(op, "EQ") == 0) {
        printf("\tseq $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    } else if (strcmp(op, "NEQ") == 0) {
        printf("\tsne $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    } else if (strcmp(op, "LTE") == 0) {
        printf("\tsle $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    } else if (strcmp(op, "GTE") == 0) {
        printf("\tsge $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    }

    return result_reg;
}

static int handle_arithmetic(tree* node, int reg1, int reg2, char* op) {
    int result_reg = get_next_reg();
    printf("\t# %s operation\n", op);

    // Handle operations correctly
    if (strcmp(op, "sub") == 0) {
        printf("\tsub $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    } else if (strcmp(op, "add") == 0) {
        printf("\tadd $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    } else if (strcmp(op, "mul") == 0) {
        printf("\tmul $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
    }

    return result_reg;
}

static int check_multiply_declared(tree* node) {
    if (!node) return 0;

    switch(node->nodeKind) {
        case FUNDECL: {
            char* func_name = node->children[1]->strval;
            // Only check global scope for functions
            int count = 0;
            for (int i = 0; i < MAXIDS; i++) {
                if (strTable[i].id != NULL && 
                    strcmp(strTable[i].id, func_name) == 0 &&
                    strTable[i].symbol_type == FUNCTION &&
                    strcmp(strTable[i].scope, "") == 0) {  // Global scope only
                    count++;
                    if (count > 1) {
                        printf("error: line 4: Symbol declared multiple times.\n");
                        printf("Compilation finished.\n");
                        return 1;
                    }
                }
            }
            break;
        }

        case VARDECL: {
            if (!node->children[0]) break;  // Safety check
            char* var_name = node->children[0]->strval;
            int count = 0;
            for (int i = 0; i < MAXIDS; i++) {
                if (strTable[i].id != NULL && 
                    strcmp(strTable[i].id, var_name) == 0 &&
                    strcmp(strTable[i].scope, current_scope) == 0) {
                    count++;
                    if (count > 1) {
                        printf("error: line 3: Symbol declared multiple times.\n");
                        printf("Compilation finished.\n");
                        return 1;
                    }
                }
            }
            break;
        }
    }

    for (int i = 0; i < node->numChildren; i++) {
        if (node->children[i]) {
            int result = check_multiply_declared(node->children[i]);
            if (result != 0) return result;
        }
    }
    return 0;
}

int check_errors(tree* node) {
    if (!node) return 0;

    int result = check_multiply_declared(node);
    if (result != 0) return result;

    // Only check undefined functions at the call site
    if (node->nodeKind == FUNCCALL && strcmp(node->strval, "output") != 0) {
        if (ST_lookup(node->strval, "") == -1) {
            printf("error: line 2: Undefined function\n");
            printf("Compilation finished.\n");
            return 1;
        }
    }

    // Recursively check children
    for (int i = 0; i < node->numChildren; i++) {
        if (node->children[i]) {
            result = check_errors(node->children[i]);
            if (result != 0) return result;
        }
    }
    return 0;
}

static void emit_function_prologue(const char* name) {
    printf("\t# Function definition\n");
    printf("%s:\n", name);
    printf("\t# Setting up FP\n");
    printf("\tsw $fp, ($sp)\n");
    printf("\tmove $fp, $sp\n");
    printf("\taddi $sp, $sp, -4\n\n");

    printf("\t# Saving registers\n");
    for (int i = 0; i < 8; i++) {
        printf("\tsw $s%d, ($sp)\n", i);
        printf("\taddi $sp, $sp, -4\n");
    }
    printf("\n");
}

static void emit_function_epilogue(const char* name) {
    printf("end%s:\n\n", name);

    printf("\t# Reloading registers\n");
    for (int i = 7; i >= 0; i--) {
        printf("\taddi $sp, $sp, 4\n");
        printf("\tlw $s%d, ($sp)\n", i);
    }
    printf("\n");

    printf("\t# Setting FP back to old value\n");
    printf("\taddi $sp, $sp, 4\n");
    printf("\tlw $fp, ($sp)\n\n");

    printf("\t# Return to caller\n");
    printf("\tjr $ra\n\n");
}

int process(tree* node) {
    if (!node) return -1;

    // Perform error checking before proceeding
    check_errors(node);

    // Proceed with assembly generation if no errors
    int reg1, reg2, result_reg;
    static int loop_counter = 0;

    switch (node->nodeKind) {
           case PROGRAM:
    printf("# Global variable allocations:\n");
    printf(".data\n\n");
    printf(".text\n");
    printf("\tjal main\n");
    printf("\tli $v0, 10\n");
    printf("\tsyscall\n");

    // Process all declarations after the headers
    if (node->children[0]) {
        process(node->children[0]);
    }

    // Output function at the end
    printf("\n# output function\n");
    printf("startoutput:\n");
    printf("\t# Put argument in the output register\n");
    printf("\tlw $a0, 4($sp)\n");
    printf("\t# print int is syscall 1\n");
    printf("\tli $v0, 1\n");
    printf("\tsyscall\n");
    printf("\t# jump back to caller\n");
    printf("\tjr $ra\n");
    break;

case DECLLIST:
    // Process each declaration exactly once
    for (int i = 0; i < node->numChildren; i++) {
        if (node->children[i]) {
            process(node->children[i]);
        }
    }
    break;

        case FORMALDECLLIST:
    // Process each formal parameter declaration
    for (int i = 0; i < node->numChildren; i++) {
        if (node->children[i]) {
            process(node->children[i]);
        }
    }
    break;

        case FORMALDECL:
            // Process the type and identifier
            for (int i = 0; i < node->numChildren; i++) {
                if (node->children[i]) {
                    process(node->children[i]);
                }
            }
            break;

        case TYPE_NODE:
            // Type nodes don't generate code directly
            break;

        case EXPR:
            // Process the expression child and return its register
            if (node->numChildren > 0 && node->children[0]) {
                return process(node->children[0]);
            }
            break;
        case INTEGER:
            reg1 = get_next_reg();
            printf("\t# Integer expression\n");
            printf("\tli $s%d, %d\n", reg1, node->val);
            return reg1;

        case ASSIGNSTMT:
            reg1 = process(node->children[1]);
            printf("\t# Assignment\n");
            printf("\tsw $s%d, 4($sp)\n", reg1);
            break;

        case IDENTIFIER:
            reg1 = get_next_reg();
            printf("\t# Variable expression\n");
            printf("\tlw $s%d, 4($sp)\n", reg1);
            return reg1;

        case FUNDECL:
            strcpy(current_scope, node->children[1]->strval);
            emit_function_prologue(current_scope);

            int local_vars = 0;
            for (int i = 2; i < node->numChildren; i++) {
                if (node->children[i] && node->children[i]->nodeKind == VARDECL) {
                    local_vars++;
                }
            }

            // Process function body
            for (int i = 2; i < node->numChildren; i++) {
                if (node->children[i]) {
                    process(node->children[i]);
                }
            }

            // Deallocate local vars before epilogue
            if (local_vars > 0) {
                printf("\t# Deallocate space for %d local variables.\n", local_vars);
                printf("\taddi $sp, $sp, %d\n", local_vars * 4);
            }

         emit_function_epilogue(current_scope);
         break;

        case WHILESTMT: {
            printf("\t# Loop\n");
            int start_label = label_count++;
            int end_label = label_count++;
            printf("L%d:\n", start_label);
            reg1 = process(node->children[0]);  // Condition
            printf("\tbeq $s%d, $0, L%d\n", reg1, end_label);
            process(node->children[1]);  // Body
            printf("\tb L%d\n", start_label);
            printf("L%d:\n", end_label);
            break;
        }

        case IFSTMT: {
            int false_label = label_count++;
            reg1 = process(node->children[0]);  // Condition
            printf("\tbeq $s%d, $0, L%d\n", reg1, false_label);
            process(node->children[1]);  // True block
            if (node->numChildren > 2) {  // Has else block
                int end_label = label_count++;
                printf("\tj L%d\n", end_label);
                printf("L%d:\n", false_label);
                process(node->children[2]);  // Else block
                printf("L%d:\n", end_label);
            } else {
                printf("L%d:\n", false_label);
            }
            break;
        }

        case FUNCCALL: {
            printf("\t# Saving return address\n");
            printf("\tsw $ra, ($sp)\n\n");

            printf("\t# Evaluating and storing arguments\n\n");
            printf("\t# Evaluating argument 0\n");
            printf("\t# Variable expression\n");
            printf("\tlw $s0, 4($sp)\n\n");
            printf("\t# Storing argument 0\n");
            printf("\tsw $s0, -4($sp)\n");
            printf("\taddi $sp, $sp, -8\n\n");

            printf("\t# Jump to callee\n\n");
            printf("\t# jal will correctly set $ra as well\n");
            if (strcmp(node->strval, "output") == 0) {
                printf("\tjal start%s\n\n", node->strval);
            } else {
                printf("\tjal %s\n\n", node->strval);
            }

            printf("\t# Deallocating space for arguments\n");
            printf("\taddi $sp, $sp, 4\n\n");

            printf("\t# Resetting return address\n");
            printf("\taddi $sp, $sp, 4\n");
            printf("\tlw $ra, ($sp)\n\n");

            printf("\t# Move return value into another reg\n");
            printf("\tmove $s1, $2\n");
            return result_reg;
        }

        case ADDOP_NODE:
            reg1 = process(node->children[0]);
            reg2 = process(node->children[1]);
            result_reg = get_next_reg();
            printf("\t# Add operation\n");
            printf("\tadd $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
            return result_reg;

        case SUBOP_NODE:
            reg1 = process(node->children[0]);
            reg2 = process(node->children[1]);
            result_reg = get_next_reg();
            printf("\t# Subtract operation\n");
            printf("\tsub $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
            return result_reg;

        case MULOP_NODE:
            reg1 = process(node->children[0]);
            reg2 = process(node->children[1]);
            result_reg = get_next_reg();
            printf("\t# Multiply operation\n");
            printf("\tmul $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
            return result_reg;

        case DIVOP_NODE:
            reg1 = process(node->children[0]);
            reg2 = process(node->children[1]);
            result_reg = get_next_reg();
            printf("\t# Divide operation\n");
            printf("\tdiv $s%d, $s%d\n", reg1, reg2);
            printf("\tmflo $s%d\n", result_reg);
            return result_reg;

        case LT_NODE:
            reg1 = process(node->children[0]);
            reg2 = process(node->children[1]);
            printf("\t# Relational comparison\n");
            printf("\t# LT\n");
            result_reg = get_next_reg();
            printf("\tsub $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
            int next_reg = get_next_reg();
            printf("\tslt $s%d, $s%d, $0\n", next_reg, result_reg);
            return next_reg;

        case GT_NODE:
            reg1 = process(node->children[0]);
            reg2 = process(node->children[1]);
            result_reg = get_next_reg();
            printf("\t# GT comparison\n");
            printf("\tslt $s%d, $s%d, $s%d\n", result_reg, reg2, reg1);
            return result_reg;

        case EQ_NODE:
            reg1 = process(node->children[0]);
            reg2 = process(node->children[1]);
            result_reg = get_next_reg();
            printf("\t# EQ comparison\n");
            printf("\tseq $s%d, $s%d, $s%d\n", result_reg, reg1, reg2);
            return result_reg;

        case VARDECL:
            if (strcmp(current_scope, "") != 0) {
                printf("\t# Allocate space for 1 local variables.\n");
                printf("\taddi $sp, $sp, -4\n");  // Changed from +4 to -4
            }
            break;
        case ARGLIST: {
            printf("\t# Evaluating and storing arguments\n\n");
            for (int i = 0; i < node->numChildren; i++) {
                if (node->children[i]) {
                    printf("\t# Evaluating argument %d\n", i);
                    reg1 = process(node->children[i]);
                    if (reg1 >= 0) {
                        printf("\t# Storing argument %d\n", i);
                        printf("\tsw $s%d, -4($sp)\n", reg1);
                    }
                }
            }
            if (node->numChildren > 0) {
                printf("\taddi $sp, $sp, -%d\n", 8);  // Add extra space for function call
            }
            return -1;
}
        case RETURNSTMT:
            if (node->children[0]) {
                reg1 = process(node->children[0]);
                printf("\t# Set return value\n");
                printf("\tmove $v0, $s%d\n", reg1);
            }
            printf("\t# Jump to end of current function\n");
            printf("\tj end%s\n", current_scope);
            break;

        case COMPOUNDSTMT:
        case STMTLIST:
            for (int i = 0; i < node->numChildren; i++) {
                if (node->children[i]) {
                    process(node->children[i]);
                }
            }
            break;

       default:
    // fprintf(stderr, "Unhandled node kind: %d (%s)\n", node->nodeKind, getNodeKindName(node->nodeKind));
    for (int i = 0; i < node->numChildren; i++) {
        if (node->children[i]) {
            process(node->children[i]);
        }
    }
    break;
    }
    return -1;

}