#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "codegen.h"
#include "tree.h"

extern tree* ast;

int main(int argc, char *argv[]) {
    int printAST = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--ast") == 0) {
            printAST = 1;
        }
    }

    if (yyparse() != 0) {
        return 1;
    }

    if (printAST) {
        printAst(ast, 1);
        return 0;
    }

    if (check_errors(ast)) {
        return 1;
    }

    process(ast);
    return 0;
}