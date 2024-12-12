#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "strtab.h"

struct strEntry strTable[MAXIDS];

// Array for mapping enum dataType to strings
const char *types[] = {"INT_TYPE", "CHAR_TYPE", "VOID_TYPE"};

// Array for mapping enum symbolType to strings
const char *symTypeMod[] = {"SCALAR", "ARRAY", "FUNCTION"};

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int ST_insert(char *id, char *scope, int data_type, int symbol_type) {
    char temp[100];
    sprintf(temp, "%s%s", scope, id);
    unsigned long hash_key = hash((unsigned char*)temp) % MAXIDS;

    int index = ST_lookup(id, scope);
    if (index != -1) {
        return index;
    }

    while (strTable[hash_key].id != NULL) {
        hash_key = (hash_key + 1) % MAXIDS;
    }

    strTable[hash_key].id = strdup(id);
    strTable[hash_key].scope = strdup(scope);
    strTable[hash_key].data_type = data_type;
    strTable[hash_key].symbol_type = symbol_type;

    return hash_key;
}

int ST_lookup(char *id, char *scope) {
    char temp[100];
    sprintf(temp, "%s%s", scope, id);
    unsigned long hash_key = hash((unsigned char*)temp) % MAXIDS;

    while (strTable[hash_key].id != NULL) {
        if (strcmp(strTable[hash_key].id, id) == 0 && strcmp(strTable[hash_key].scope, scope) == 0) {
            return hash_key;
        }
        hash_key = (hash_key + 1) % MAXIDS;
    }

    return -1;
}

void output_entry(int i) {
    printf("%d: %s ", i, types[strTable[i].data_type]);
    printf("%s:%s%s\n", strTable[i].scope, strTable[i].id, symTypeMod[strTable[i].symbol_type]);
}
