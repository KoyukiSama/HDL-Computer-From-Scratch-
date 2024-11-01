#include "symbol_table.h"

symboltable_t* symboltable_init(size_t initial_capacity) {

    // Symbol table
    symboltable_t* SymbolTable = MallocExit(sizeof(*SymbolTable));
    SymbolTable->capacity = initial_capacity;
    SymbolTable->size     = 0;

    // Bucket list
    bucket_t** BucketList = SymbolTable->BucketList = Calloc(initial_capacity, sizeof(*BucketList));
    if (BucketList == NULL) { // free symboltable if error
        free(SymbolTable);
        exit(EXIT_FAILURE);
    }

    return SymbolTable;
}

void symboltable_destroy(symboltable_t *SymbolTable) {

    // check if null
    if (SymbolTable == NULL) return;

    // Bucket list items destroy
    for (size_t i = 0; i < SymbolTable->capacity; i++) {
        bucket_t *current = SymbolTable->BucketList[i];

        while (current == NULL) {
            bucket_t *next = current->next;
            free(current->symbol);              // maybe unneccessary if I don't have to malloc a string
            free(current);
            current = next;
        }
    }

    // Bucket list destroy
    free(SymbolTable->BucketList);

    // Symbol table destroy
    free(SymbolTable);
}


char symboltable_set(symboltable_t *SymbolTable, const char* symbol, unsigned short value) {
    
    // get hashkey
    unsigned short key = symboltable_hashcode(SymbolTable, symbol);

    // save the current bucket that will be worked on
    bucket_t *currBucket = SymbolTable->BucketList[key];

    // go to furthest collission bucket, check if key already exists
    if (currBucket) {
        if (strcmp(currBucket->symbol, symbol) == 0) {
            currBucket->value = value;
            return -1;
        }
        currBucket = currBucket->next;
    }

    // change capacity if needed
    symboltable_ensure_capacity( SymbolTable );

    // key not in symbol table, alloc new 
    bucket_t *bucket = CallocExit(1, sizeof(*bucket));
    bucket->symbol   = symbol;
    bucket->value    = value;
    bucket->next     = SymbolTable->BucketList[key];

    //shift the open space to the front
    SymbolTable->BucketList[key] = bucket;
    SymbolTable->size++;

    return 0;
}

void* symboltable_get(symboltable_t *SymbolTable, const char* symbol) {
    bucket_t *currBucket = SymbolTable->BucketList[symboltable_hashcode(SymbolTable, symbol)];

    while (currBucket) {
        if (strcmp(currBucket->symbol, symbol) == 0) {
            return currBucket->value;
        }
        currBucket = currBucket->next;
    }
    
    return NULL;
}



//// helper functions
unsigned short  symboltable_hashcode(symboltable_t *SymbolTable, const char* symbol) {
    unsigned long hash = 5381; // starting prime
    int c;

    while (c = *symbol++) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return (unsigned short)(hash % SymbolTable->capacity);
}

void symboltable_ensure_capacity(symboltable_t *SymbolTable) {
    if ( SymbolTable->size > (SymbolTable->capacity * LOAD_FACTOR) ) {

        // set new capacity
        size_t capacity_old = SymbolTable->capacity;
        size_t capacity_new = SymbolTable->capacity = SymbolTable->capacity * GROWTH_FACTOR;
        
        // re memory
        bucket_t** new_list = realloc(SymbolTable->BucketList, capacity_new * sizeof(*new_list));
        if (new_list == NULL) {
            perror("Realloc error");
            exit(EXIT_FAILURE);
        }
        for (size_t i = capacity_old; i < capacity_new; i++) { // fake calloc
            new_list[i] = NULL;
        }

        // set 
        SymbolTable->BucketList = new_list;
    }
    return;
}

// malloc wrapper

void* Malloc(size_t size_t) {
    void *ptr = malloc(size_t);
    if ( ptr == NULL ) {
        perror("Malloc error");
    }
    return ptr;
}

void* Calloc(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if ( ptr == NULL ) {
        perror("Malloc error");
    }
    return ptr;
}

void* CallocExit(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if ( ptr == NULL ) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
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