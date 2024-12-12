#ifndef STRTAB_H
#define STRTAB_H
#define MAXIDS 1000

// Extern declarations from lex/yacc
extern int yylineno;
extern int yycol;
extern void report_error(const char* format, ...);

// Enhanced type system
enum dataType {INT_TYPE, CHAR_TYPE, VOID_TYPE};
enum symbolType {SCALAR, ARRAY, FUNCTION};
enum errorType {
    ERR_UNDECLARED,
    ERR_REDECLARED,
    ERR_TYPE_MISMATCH,
    ERR_PARAM_MISMATCH,
    ERR_ARRAY_INDEX,
    ERR_VOID_VAR,
    ERR_FUNCTION_CALL
};

// Forward declarations
struct table_node;
typedef struct table_node table_node;
struct treenode;
typedef struct treenode tree;

// Parameter structure
typedef struct param {
    int data_type;
    int symbol_type;
    char* name;        // Added for better error reporting
    struct param* next;
} param;

// Symbol table entry structure
typedef struct strEntry {
    char* id;
    char* scope;
    int data_type;
    int symbol_type;
    int size;          // Num elements if array, num params if function
    int line;          // Line where declared
    int column;        // Column where declared
    param* params;     // Parameters for functions
    int is_defined;    // For functions: declared vs defined
} symEntry;

// Table node structure
struct table_node {
    symEntry* strTable[MAXIDS];
    int numChildren;
    char* scope_name;  // Added for better error reporting
    struct table_node* parent;
    struct table_node* first_child;
    struct table_node* last_child;
    struct table_node* next;
};

// Global variable
extern table_node* current_scope;

// Core symbol table functions
int ST_insert(char *id, int data_type, int symbol_type, int* scope);
symEntry* ST_lookup(char *id);
void add_param(int data_type, int symbol_type);
void connect_params(int index, int num_params);
void new_scope(char* scope_name);
void up_scope();


int count_args(tree* arglist);
int check_arg_type(param* formal, tree* arg);


// Hash function (moved from static to public)
int hash(char* id);

// Enhanced semantic analysis functions
int check_param_match(param* formal, param* actual);
int is_type_compatible(int type1, int type2);
symEntry* lookup_in_current_scope(char *id);
void set_function_defined(char *id);
int check_array_bounds(char *id, int index);
void print_sym_tab();
int isValidIntegerConstant(const char* str);

// Error reporting functions
void report_semantic_error(enum errorType error, char* id, int line, int col);
const char* get_type_name(int data_type);
const char* get_symbol_type_name(int symbol_type);

// Helper functions for semantic analysis
int get_array_size(char *id);
int is_function_defined(char *id);
int get_param_count(char *id);
param* get_param_list(char *id);

#endif
