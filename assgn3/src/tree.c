#include<tree.h>
#include<strtab.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int yylineno;
extern int yycol;
extern table_node* current_scope;

/* Enhanced node type strings */
char *nodeNames[33] = {"program", "declList", "decl", "varDecl", "typeSpecifier",
                       "funDecl", "formalDeclList", "formalDecl", "funBody",
                       "localDeclList", "statementList", "statement", "compoundStmt",
                       "assignStmt", "condStmt", "loopStmt", "returnStmt", "expression",
                       "relop", "addExpr", "addop", "term", "mulop", "factor",
                       "funcCallExpr", "argList", "integer", "identifier", "var",
                       "arrayDecl", "char", "funcTypeName"};

char *typeNames[3] = {"int", "char", "void"};
char *ops[10] = {"+", "-", "*", "/", "<", "<=", "==", ">=", ">", "!="};

char* get_symbol_id(int index) {
    if (current_scope == NULL) return NULL;

    table_node* scope = current_scope;
    while (scope != NULL) {
        if (scope->strTable[index] != NULL) {
            return scope->strTable[index]->id;
        }
        scope = scope->parent;
    }
    return NULL;
}

tree *maketree(int kind) {
    tree *this = (tree *) malloc(sizeof(struct treenode));
    this->nodeKind = kind;
    this->numChildren = 0;
    this->errors = NULL;
    this->line = yylineno;
    this->column = yycol;
    return this;
}

tree *maketreeWithVal(int kind, int val) {
    tree *this = maketree(kind);
    this->val = val;
    return this;
}

void addChild(tree *parent, tree *child) {
    if (parent->numChildren == MAXCHILDREN) {
        printf("Error: Cannot add child to parent node\n");
        exit(1);
    }
    child->parent = parent;
    nextAvailChild(parent) = child;
    parent->numChildren++;
}

void addSemanticError(tree *node, char *message) {
    semantic_error *error = malloc(sizeof(semantic_error));
    error->message = strdup(message);
    error->line = node->line;
    error->column = node->column;
    error->next = node->errors;
    node->errors = error;
}

int checkTypes(tree *node1, tree *node2) {
    if (node1->type != node2->type) {
        return 0;
    }
    if (node1->sym_type != node2->sym_type) {
        return 0;
    }
    return 1;
}

int isArrayIndexValid(tree *node) {
    if (node->nodeKind == INT_CONST_NODE) {
        return (node->val >= 0 && node->val < node->array_size);
    }
    return 1; // For non-constant indices, we can't check at compile time
}

void setNodeLocation(tree *node, int line, int col) {
    node->line = line;
    node->column = col;
}

int getNodeDataType(tree *node) {
    switch(node->nodeKind) {
        case INT_CONST_NODE:
            return INT_TYPE;
        case CHAR_CONST_NODE:
            return CHAR_TYPE;
        case ID_NODE:
        case VAR_NODE:
            return node->type;
        default:
            return -1;
    }
}

void printSemanticErrors(tree *root) {
    if (!root) return;

    // Print errors for current node
    semantic_error *error = root->errors;
    while (error) {
        fprintf(stderr, "Line %d, Column %d: %s\n",
                error->line, error->column, error->message);
        error = error->next;
    }

    // Recursively print errors for children
    for (int i = 0; i < root->numChildren; i++) {
        printSemanticErrors(getChild(root, i));
    }
}

void printAst(tree *node, int nestLevel) {
    char* nodeName = nodeNames[node->nodeKind];
    if(strcmp(nodeName,"identifier") == 0){
        if(node->val == -1)
            printf("%s,%s\n", nodeName,"undeclared variable");
        else
            printf("%s,%s\n", nodeName,get_symbol_id(node->val));
    }
    else if(strcmp(nodeName,"integer") == 0){
        printf("%s,%d\n", nodeName,node->val);
    }
    else if(strcmp(nodeName,"char") == 0){
        printf("%s,%c\n", nodeName,node->val);
    }
    else if(strcmp(nodeName,"typeSpecifier") == 0){
        printf("%s,%s\n", nodeName,typeNames[node->val]);
    }
    else if(strcmp(nodeName,"relop") == 0 || strcmp(nodeName,"mulop") == 0 || strcmp(nodeName,"addop") == 0){
        printf("%s,%s\n", nodeName,ops[node->val]);
    }
    else{
        printf("%s\n", nodeName);
    }

    int i, j;
    for (i = 0; i < node->numChildren; i++)  {
        for (j = 0; j < nestLevel; j++)
            printf("    ");
        printAst(getChild(node, i), nestLevel + 1);
    }
}
