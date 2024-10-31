#include "symbol_table.h"

symboltable_t* symboltable_init(size_t initial_capacity) {

    // Symbol table
    symboltable_t* SymbolTable = MallocExit(sizeof(*SymbolTable));
    SymbolTable->capacity = initial_capacity;
    SymbolTable->size = 0;

    // Bucket list
    bucket_t** BucketList = SymbolTable->BucketList = Malloc(sizeof(**BucketList) * initial_capacity);
    if (BucketList == NULL) { // free symboltable if error
        free(SymbolTable);
        exit(EXIT_FAILURE);
    }

    return SymbolTable;
}

void symboltable_destroy (symboltable_t *SymbolTable) {

    // check if null
    if (SymbolTable == NULL) return;

    // Bucket list items destroy
    for (size_t i = 0; i < SymbolTable->capacity; i++) {
        bucket_t *current = SymbolTable->BucketList[i];

        while (current != NULL) {
            bucket_t *next = current->next;
            free(current->symbol);
            free(current);
            current = next;
        }
    }

    // Bucket list destroy
    free(SymbolTable->BucketList);

    // Symbol table destroy
    free(SymbolTable);
}

unsigned short  symboltable_hashcode (symboltable_t *SymbolTable, const char* symbol) {
    unsigned long hash = 5381; // starting prime
    int c;

    while (c = *symbol++) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return (unsigned short)(hash % SymbolTable->capacity);
}

void* symboltable_set (symboltable_t *SymbolTable, char* symbol, unsigned short value);

void* symboltable_get (symboltable_t *SymbolTable, char* symbol);


// malloc wrapper

void* Malloc(size_t size_t) {
    void *ptr = malloc(size_t);
    if ( ptr == NULL ) {
        perror("Malloc error");
    }
    return ptr;
}

void* MallocExit(size_t size_t) {
    void *ptr = malloc(size_t);
    if ( ptr == NULL ) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}