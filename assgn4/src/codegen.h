#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"

// Function declarations
int check_errors(tree* node);
int process(tree* node);

// Error flags should be declared here
extern int has_multiply_declared_var;
extern int has_multiply_declared_func;
extern int has_undeclared_var;
extern int has_undeclared_func;
extern int has_function_mismatch;

#endif