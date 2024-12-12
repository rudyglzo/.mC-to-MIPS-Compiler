#ifndef TREE_H
#define TREE_H

#define MAXCHILDREN 12

/* Global AST root */
extern struct treenode *ast;  // Correctly declare as an external variable

/* Node types for AST */
enum nodeTypes {
    PROGRAM = 1000,
    DECLLIST,
    DECL,
    VARDECL,
    TYPESPEC,
    ASSIGNSTMT,
    IFSTMT,
    LOOPSTMT,
    RETURNSTMT,
    EXPR,
    FUNCCALL,
    ARGLIST,
    INTEGER,
    IDENTIFIER,
    RELOP_NODE,
    FUNDECL,
    ARRAY_ACCESS,
    CONDSTMT,
    WHILESTMT,
    COMPOUNDSTMT,
    FORMALDECLLIST,
    FORMALDECL,
    TYPE_NODE,        // Added TYPE_NODE
    STMTLIST,
    EXPRESSION,
    ADDEXPR,
    SUBEXPR,
    TERM,
    FACTOR,
    ADDOP_NODE,       // Renamed from ADDOP
    SUBOP_NODE,       // Renamed from SUBOP
    MULOP_NODE,       // Renamed from MULOP
    DIVOP_NODE,       // Renamed from DIVOP
    LT_NODE,          // Renamed from LT
    GT_NODE,          // Renamed from GT
    EQ_NODE,          // Renamed from EQ
    NEQ_NODE,         // For '!=' operator
    LTE_NODE,         // For '<=' operator
    GTE_NODE,         // For '>=' operator
    CHAR_NODE,        // For character constants
    ERROR_NODE,       // For error handling
    ARRAY_NODE       // For array declarations
   // DO_NODE,
   // WHILE_NODE,
    
    // Add any other node kinds needed

};

/* Define tree as struct treenode */
typedef struct treenode {
    int nodeKind;  // Node type (from nodeTypes)
    int numChildren;
    int val;       // For constants (integer values)
    char *strval;  // For identifiers (string values)
    struct treenode *parent;
    struct treenode *children[MAXCHILDREN];
} tree;

/* Function declarations */
tree *maketree(int kind);
tree *maketreeWithVal(int kind, int val);
tree *maketreeWithStrVal(int kind, char *strval);
void addChild(tree *parent, tree *child);
void printAst(tree *root, int nestLevel);

#endif
