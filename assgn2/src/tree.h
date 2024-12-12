#ifndef TREE_H
#define TREE_H

#define MAXCHILDREN 12

/* Global AST root */
extern struct treenode *ast;  // Correctly declare as an external variable

/* Node types for AST */
enum nodeTypes {
    PROGRAM, DECLLIST, DECL, VARDECL, TYPESPEC,
    ASSIGNSTMT, IFSTMT, LOOPSTMT, RETURNSTMT, EXPR,
    FUNCCALL, ARGLIST, INTEGER, IDENTIFIER, RELOP_NODE, FUNDECL,
    ARRAY_ACCESS, CONDSTMT, WHILESTMT, COMPOUNDSTMT, FORMALDECLLIST, FORMALDECL, TYPE, STMTLIST
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
