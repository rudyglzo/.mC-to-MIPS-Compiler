#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include "../src/tree.h"
#include "../src/strtab.h"

param *working_list_head = NULL;
param *working_list_end = NULL;
table_node* current_scope = NULL;

// Error messages for semantic analysis
const char* error_messages[] = {
    "Undeclared identifier: %s",
    "Redeclaration of identifier: %s",
    "Type mismatch involving identifier: %s",
    "Parameter mismatch in function: %s",
    "Invalid array index for array: %s",
    "Cannot declare void variable: %s",
    "Invalid function call: %s"
};

int hash(char* id) {
    unsigned int hash = 0;
    for (int i = 0; id[i] != '\0'; i++) {
        hash = 31 * hash + id[i];
    }
    return hash % MAXIDS;
}

int count_args(tree* arglist) {
    return arglist ? arglist->numChildren : 0;
}

int check_arg_type(param* formal, tree* arg) {
    // Handle array arguments specially
    if (formal->symbol_type == ARRAY) {
        return arg->sym_type == ARRAY && 
               is_type_compatible(formal->data_type, arg->type);
    }
    return is_type_compatible(formal->data_type, arg->type);
}

void report_semantic_error(enum errorType error, char* id, int line, int col) {
    fprintf(stderr, "error: line %d: ", line);
    switch(error) {
        case ERR_UNDECLARED:
            fprintf(stderr, "Undeclared variable\n");
            break;
        case ERR_REDECLARED:
            fprintf(stderr, "Symbol declared multiple times\n");
            break;
        case ERR_TYPE_MISMATCH:
            fprintf(stderr, "Type mismatch in assignment\n");
            break;
        case ERR_PARAM_MISMATCH:
            fprintf(stderr, "Parameter mismatch in function call\n");
            break;
        case ERR_ARRAY_INDEX:
            fprintf(stderr, "Invalid array index\n");
            break;
        case ERR_VOID_VAR:
            fprintf(stderr, "Cannot declare void variable\n");
            break;
        case ERR_FUNCTION_CALL:
            fprintf(stderr, "Invalid function call\n");
            break;
    }
}

const char* get_type_name(int data_type) {
    switch(data_type) {
        case INT_TYPE: return "int";
        case CHAR_TYPE: return "char";
        case VOID_TYPE: return "void";
        default: return "unknown";
    }
}

const char* get_symbol_type_name(int symbol_type) {
    switch(symbol_type) {
        case SCALAR: return "scalar";
        case ARRAY: return "array";
        case FUNCTION: return "function";
        default: return "unknown";
    }
}

int ST_insert(char *id, int data_type, int symbol_type, int* scope) {
    if (!current_scope) {
        new_scope("global");
    }

    symEntry* existing = lookup_in_current_scope(id);
    if (existing) {
        report_error("Symbol declared multiple times");
        return -1;
    }

    symEntry* entry = (symEntry*)malloc(sizeof(symEntry));
    if (!entry) return -1;
    
    entry->id = strdup(id);
    entry->data_type = data_type;
    entry->symbol_type = symbol_type;
    entry->size = 0;
    entry->params = NULL;

    int index = hash(id);
    int original = index;
    
    do {
        if (!current_scope->strTable[index]) {
            current_scope->strTable[index] = entry;
            *scope = index;
            return index;
        }
        index = (index + 1) % MAXIDS;
    } while (index != original);
    
    free(entry->id);
    free(entry);
    return -1;
}

symEntry* ST_lookup(char *id) {
    table_node* scope = current_scope;

    while (scope != NULL) {
        int index = hash(id);
        int original = index;

        do {
            symEntry* entry = scope->strTable[index];
            if (entry != NULL && strcmp(entry->id, id) == 0) {
                return entry;
            }
            index = (index + 1) % MAXIDS;
        } while (index != original && scope->strTable[index] != NULL);

        scope = scope->parent;
    }

    report_semantic_error(ERR_UNDECLARED, id, yylineno, yycol);
    return NULL;
}

symEntry* lookup_in_current_scope(char *id) {
    if (!current_scope) return NULL;

    int index = hash(id);
    int original = index;

    do {
        symEntry* entry = current_scope->strTable[index];
        if (entry && strcmp(entry->id, id) == 0) {
            return entry;
        }
        index = (index + 1) % MAXIDS;
    } while (index != original && current_scope->strTable[index] != NULL);

    return NULL;
}

void add_param(int data_type, int symbol_type) {
    param* new_param = (param*)malloc(sizeof(param));
    new_param->data_type = data_type;
    new_param->symbol_type = symbol_type;
    new_param->next = NULL;
    
    if (working_list_head == NULL) {
        working_list_head = new_param;
        working_list_end = new_param;
    } else {
        working_list_end->next = new_param;
        working_list_end = new_param;
    }
}

void connect_params(int index, int num_params) {
    if (!current_scope || !current_scope->parent) return;
    
    symEntry* func = current_scope->parent->strTable[index];
    if (!func) return;
    
    func->params = working_list_head;
    func->size = num_params;
    
    working_list_head = NULL;
    working_list_end = NULL;
}

void new_scope(char* scope_name) {
    table_node* new_node = (table_node*)malloc(sizeof(table_node));
    new_node->numChildren = 0;
    new_node->scope_name = strdup(scope_name);
    new_node->parent = current_scope;
    new_node->first_child = NULL;
    new_node->last_child = NULL;
    new_node->next = NULL;
    
    for (int i = 0; i < MAXIDS; i++) {
        new_node->strTable[i] = NULL;
    }
    
    if (current_scope) {
        if (!current_scope->first_child) {
            current_scope->first_child = new_node;
        } else {
            current_scope->last_child->next = new_node;
        }
        current_scope->last_child = new_node;
        current_scope->numChildren++;
    }
    
    current_scope = new_node;
}

void up_scope() {
    if (current_scope) {
        current_scope = current_scope->parent;
    }
}

int check_param_match(param* formal, param* actual) {
    while (formal && actual) {
        if (formal->data_type != actual->data_type ||
            formal->symbol_type != actual->symbol_type) {
            return 0;
        }
        formal = formal->next;
        actual = actual->next;
    }
    return formal == NULL && actual == NULL;
}

int is_type_compatible(int type1, int type2) {
    if (type1 == type2) return 1;
    // Only allow char to int promotion
    if (type1 == INT_TYPE && type2 == CHAR_TYPE) return 1;
    return 0;
}

int check_array_bounds(char *id, int index) {
    symEntry* entry = ST_lookup(id);
    if (!entry || entry->symbol_type != ARRAY) return 0;
    if (entry->size <= 0) return 1; // Can't check bounds for unsized arrays
    return index >= 0 && index < entry->size;
}

int isValidIntegerConstant(const char* str) {
    char* endptr;
    long long val = strtoll(str, &endptr, 10);
    return (*endptr == '\0' && val >= INT_MIN && val <= INT_MAX);
}

void set_function_defined(char *id) {
    symEntry* entry = ST_lookup(id);
    if (entry && entry->symbol_type == FUNCTION) {
        entry->is_defined = 1;
    }
}

int get_array_size(char *id) {
    symEntry* entry = ST_lookup(id);
    return (entry && entry->symbol_type == ARRAY) ? entry->size : -1;
}

int is_function_defined(char *id) {
    symEntry* entry = ST_lookup(id);
    return (entry && entry->symbol_type == FUNCTION) ? entry->is_defined : 0;
}

int get_param_count(char *id) {
    symEntry* entry = ST_lookup(id);
    return (entry && entry->symbol_type == FUNCTION) ? entry->size : -1;
}

param* get_param_list(char *id) {
    symEntry* entry = ST_lookup(id);
    return (entry && entry->symbol_type == FUNCTION) ? entry->params : NULL;
}

void print_sym_tab() {
    printf("\nSymbol Table Contents:\n");
    printf("====================\n\n");

    void print_scope_table(table_node* scope, int level) {
        if (!scope) return;

        // Print scope header
        for (int i = 0; i < level; i++) printf("  ");
        printf("Scope: %s\n", scope->scope_name);

        // Print symbols in current scope
        for (int i = 0; i < MAXIDS; i++) {
            symEntry* entry = scope->strTable[i];
            if (entry) {
                for (int j = 0; j < level + 1; j++) printf("  ");
                printf("%-15s | %-6s | %-8s", 
                    entry->id,
                    get_type_name(entry->data_type),
                    get_symbol_type_name(entry->symbol_type));

                if (entry->symbol_type == ARRAY) {
                    printf(" | size: %d", entry->size);
                }
                else if (entry->symbol_type == FUNCTION) {
                    printf(" | params: ");
                    param* p = entry->params;
                    while (p) {
                        printf("%s", get_type_name(p->data_type));
                        if (p->symbol_type == ARRAY) printf("[]");
                        if (p->next) printf(", ");
                        p = p->next;
                    }
                    printf(" | %s", entry->is_defined ? "defined" : "declared");
                }
                printf("\n");
            }
        }

        // Print child scopes
        table_node* child = scope->first_child;
        while (child) {
            print_scope_table(child, level + 1);
            child = child->next;
        }
    }

    // Find root scope
    table_node* root = current_scope;
    while (root && root->parent) root = root->parent;

    // Print entire table
    print_scope_table(root, 0);
}
