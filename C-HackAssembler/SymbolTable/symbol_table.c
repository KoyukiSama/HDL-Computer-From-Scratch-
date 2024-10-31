#include "symbol_table.h"

char symboltable_init (symboltable_t *SymbolTable, size_t initial_capacity) {
    // check if exists
    if (SymbolTable != NULL) {
        return 2;
    }

    // create symboltable
    SymbolTable->capacity = initial_capacity;
    SymbolTable->size = 0;
    bucket_t** BucketList = Malloc(sizeof(**BucketList) * initial_capacity);
}

char symboltable_destroy (symboltable_t *SymbolTable);

unsigned short  symboltable_hashcode (symboltable_t *SymbolTable, char* symbol);

void* symboltable_set (symboltable_t *SymbolTable, char* symbol, unsigned short value);

void* symboltable_get (symboltable_t *SymbolTable, char* symbol);


// mallocs

void* Malloc(size_t size_t) {
    void *ptr = malloc(size_t);
    if ( ptr == NULL ) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}