#include "symbol_table.h"

#include <stdlib.h>

#define LOAD_FACTOR 0.75;
#define GROWTH_FACTOR 2;

// symbol table data structure

typedef struct symboltable {
    bucket_t** bucketlist;
    size_t size;
    size_t capacity;
} symboltable_t;

typedef struct bucket {
    char* symbol;
    int value;
    struct bucket* next;
} bucket_t;

// symbol table functions

char    symboltable_init(  
            symboltable_t *SymbolTable,
            size_t capacity,
);

symboltable_destroy() {

}

symboltable_set() {

}

symboltable_get() {

}

// malloc handling