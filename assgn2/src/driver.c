#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"
#include "strtab.h"
#include "parser.tab.h"

int main() {
    if (!yyparse()){
        printAst(ast, 1);
/*
	printf("\n\nSYMBOL TABLE:\n");
        for(int i = 0; i < MAXIDS; i++){
            if(strTable[i].id != NULL){
                output_entry(i);
            }
        }
*/  
  }
    return 0;
}
