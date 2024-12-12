#include "tree.h"
#include "strtab.h"
#include "parser.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

tree *ast = NULL;

tree *maketree(int kind) {
    tree *newNode = (tree *)malloc(sizeof(tree));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->nodeKind = kind;
    newNode->numChildren = 0;
    newNode->val = 0;
    newNode->strval = NULL;  // Initialize strval to NULL
    newNode->parent = NULL;
    memset(newNode->children, 0, sizeof(newNode->children));
    return newNode;
}

tree *maketreeWithVal(int kind, int val) {
    tree *newNode = (tree *)malloc(sizeof(tree));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->nodeKind = kind;
    newNode->numChildren = 0;
    newNode->val = val;
    newNode->strval = NULL;  // Initialize strval to NULL
    newNode->parent = NULL;
    memset(newNode->children, 0, sizeof(newNode->children));
    return newNode;
}

tree *maketreeWithStrVal(int kind, char *strval) {
    tree *newNode = (tree *)malloc(sizeof(tree));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->nodeKind = kind;
    newNode->numChildren = 0;
    newNode->val = 0;  // Initialize val to 0 for string nodes
    newNode->strval = strdup(strval);  // Handle string value
    newNode->parent = NULL;
    memset(newNode->children, 0, sizeof(newNode->children));
    return newNode;
}

void addChild(tree *parent, tree *child) {
    if (parent->numChildren >= MAXCHILDREN) {
        printf("Error: Maximum number of children exceeded for nodeKind %d\n", parent->nodeKind);
        return;
    }
    parent->children[parent->numChildren++] = child;
    child->parent = parent;
}

void printAst(tree *root, int nestLevel) {
    if (!root) return;

    // Print indentation based on the depth of the node
    for (int i = 0; i < nestLevel; i++) {
        printf("  ");  // Two spaces for each level
    }

    // Print node type
    switch (root->nodeKind) {
        case PROGRAM:
            printf("program\n");
            break;
        case DECLLIST:
            printf("declList\n");
            break;
        case DECL:
            printf("decl\n");
            break;
        case VARDECL:
            printf("varDecl\n");
            break;
        case FUNDECL:
            printf("funDecl\n");
            break;
        case IDENTIFIER:
            printf("identifier,%s\n", root->strval);
            break;
        case INTEGER:
            printf("integer,%d\n", root->val);
            break;
        case ASSIGNSTMT:
            printf("assignStmt\n");
            break;
        case IFSTMT:
            printf("ifStmt\n");
            break;
        case WHILESTMT:
            printf("whileStmt\n");
            break;
        case ADDOP:
            printf("addop,+\n");
            break;
        case SUBOP:
            printf("subop,-\n");
            break;
        case MULOP:
            printf("mulop,*\n");
            break;
        case DIVOP:
            printf("divop,/\n");
            break;
        case RETURNSTMT:
            printf("returnStmt\n");
            break;
        case FUNCCALL:
            printf("funcCall\n");
            break;
        case ARGLIST:
            printf("argList\n");
            break;
 	case TYPESPEC:
            if (root->val == INT_TYPE)
                printf("typeSpecifier,int\n");
            else if (root->val == CHAR_TYPE)
                printf("typeSpecifier,char\n");
            else if (root->val == VOID_TYPE)
                printf("typeSpecifier,void\n");
            break;
        default:
            printf("nodeKind: %d\n", root->nodeKind);
    }

    // Recursively print the children of the node, increasing the nest level
    for (int i = 0; i < root->numChildren; i++) {
        printAst(root->children[i], nestLevel + 1);
    }
}
