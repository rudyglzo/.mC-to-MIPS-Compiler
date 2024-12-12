#ifndef TREE_H
#define TREE_H

#include "strtab.h"

#define MAXCHILDREN 100

typedef struct treenode tree;

/* Enhanced error tracking */
typedef struct semantic_error {
    char* message;
    int line;
    int column;
    struct semantic_error* next;
} semantic_error;

/* Enhanced node types for semantic analysis */
enum NodeType {
    PROGRAM_NODE, DECL_LIST_NODE, DECL_NODE, VAR_DECL_NODE,
    TYPE_SPEC_NODE, FUNC_DECL_NODE, FORMAL_DECL_LIST_NODE,
    FORMAL_DECL_NODE, FUNC_BODY_NODE, LOCAL_DECL_LIST_NODE,
    STMT_LIST_NODE, STMT_NODE, COMPOUND_STMT_NODE,
    ASSIGN_STMT_NODE, COND_STMT_NODE, LOOP_STMT_NODE,
    RETURN_STMT_NODE, EXPR_NODE, RELOP_NODE, ADD_EXPR_NODE,
    ADDOP_NODE, TERM_NODE, MULOP_NODE, FACTOR_NODE,
    FUNC_CALL_NODE, ARG_LIST_NODE, INT_CONST_NODE,
    ID_NODE, VAR_NODE, ARRAY_DECL_NODE, CHAR_CONST_NODE,
    FUNC_TYPE_NODE
};

struct treenode {
    int nodeKind;           // Type of node (from NodeType enum)
    int numChildren;
    int val;               // Value for constants
    int scope;             // Scope level
    int type;              // Data type
    int sym_type;          // SCALAR/ARRAY/FUNCTION
    int line;              // Line number for error reporting
    int column;            // Column number for error reporting
    int array_size;        // Size for array declarations
    tree *parent;
    tree *children[MAXCHILDREN];
    semantic_error *errors; // Linked list of semantic errors
};

/* pointer to AST root - declared here, defined in parser.y */
extern tree *ast;

/* Core tree building functions */
tree *maketree(int kind);
tree *maketreeWithVal(int kind, int val);
void addChild(tree *parent, tree *child);
void printAst(tree *root, int nestLevel);

/* New semantic analysis functions */
void addSemanticError(tree *node, char *message);
int checkTypes(tree *node1, tree *node2);
int isArrayIndexValid(tree *node);
void setNodeLocation(tree *node, int line, int col);
int getNodeDataType(tree *node);
char *getTypeString(int type);
void printSemanticErrors(tree *root);

/* Tree manipulation macros */
#define nextAvailChild(node) node->children[node->numChildren]
#define getChild(node, index) node->children[index]

#endif
