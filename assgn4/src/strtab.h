#ifndef STRTAB_H
#define STRTAB_H
#define MAXIDS 1000

// Enum for representing data types
enum dataType {
    INT_TYPE,  // Integer type
    CHAR_TYPE, // Character type
    VOID_TYPE  // Void type
};

// Enum for representing symbol types
enum symbolType {
    SCALAR,    // Scalar variable
    ARRAY,     // Array variable
    FUNCTION   // Function
};

// Structure for a symbol table entry
struct strEntry {
    char* id;          // Identifier name
    char* scope;       // Scope of the identifier
    int   data_type;   // Data type (e.g., INT_TYPE, CHAR_TYPE)
    int   symbol_type; // Symbol type (e.g., SCALAR, ARRAY, FUNCTION
};

// Symbol table array
extern struct strEntry strTable[MAXIDS];

// Function prototypes
int ST_insert(char *id, char *scope, int data_type, int symbol_type);  // Insert entry into symbol table
int ST_lookup(char *id, char *scope);  // Look up entry in symbol table
void output_entry(int i);  // Output entry at index i

#endif
