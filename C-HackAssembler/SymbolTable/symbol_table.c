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

void symboltable_init_predefined_symbols(symboltable_t* SymbolTable) {
    symboltable_set(SymbolTable, "@R0", 0); // REGISTER 0
    symboltable_set(SymbolTable, "@R1", 1);
    symboltable_set(SymbolTable, "@R2", 2);
    symboltable_set(SymbolTable, "@R3", 3);
    symboltable_set(SymbolTable, "@R4", 4);
    symboltable_set(SymbolTable, "@R5", 5);
    symboltable_set(SymbolTable, "@R6", 6);
    symboltable_set(SymbolTable, "@R7", 7);
    symboltable_set(SymbolTable, "@R8", 8);
    symboltable_set(SymbolTable, "@R9", 9);
    symboltable_set(SymbolTable, "@R10", 10);
    symboltable_set(SymbolTable, "@R11", 11);
    symboltable_set(SymbolTable, "@R12", 12);
    symboltable_set(SymbolTable, "@R13", 13);
    symboltable_set(SymbolTable, "@R14", 14);
    symboltable_set(SymbolTable, "@R15", 15);
    symboltable_set(SymbolTable, "@SCREEN", 16384); // SCREEN
    symboltable_set(SymbolTable, "@KBD", 24576); // KEYBOARD
    symboltable_set(SymbolTable, "@SP", 0);
    symboltable_set(SymbolTable, "@LCL", 1);
    symboltable_set(SymbolTable, "@ARG", 2);
    symboltable_set(SymbolTable, "@THIS", 3);
    symboltable_set(SymbolTable, "@THAT", 4);

    return;
}

void symboltable_destroy(symboltable_t *SymbolTable) {

    // check if null
    if (SymbolTable == NULL) return;

    // Bucket list items destroy
    for (size_t i = 0; i < SymbolTable->capacity; i++) {
        bucket_t *current = SymbolTable->BucketList[i];

        while (current) {
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
    while (currBucket) {
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
    bucket->symbol   = strdup(symbol);
    bucket->value    = value;
    bucket->next     = SymbolTable->BucketList[key];

    //shift the open space to the front
    SymbolTable->BucketList[key] = bucket;
    SymbolTable->size++;

    return 0;
}

char symboltable_get(symboltable_t *SymbolTable, const char* symbol, unsigned short *out_value) {
    bucket_t *currBucket = SymbolTable->BucketList[symboltable_hashcode(SymbolTable, symbol)];

    while (currBucket) {
        if (strcmp(currBucket->symbol, symbol) == 0) {
            *out_value = currBucket->value;
            return 0;
        }
        currBucket = currBucket->next;
    }
    return -1;
}



//// helper functions
unsigned short  symboltable_hashcode(symboltable_t *SymbolTable, const char* symbol) {
    unsigned long hash = 5381; // starting prime
    int c;

    while ((c = *symbol++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return (unsigned short)(hash % SymbolTable->capacity);
}

void symboltable_ensure_capacity(symboltable_t *SymbolTable) {
    if ( SymbolTable->size > (size_t)(SymbolTable->capacity * LOAD_FACTOR) ) {

        // set new capacity
        size_t capacity_old = SymbolTable->capacity;
        size_t capacity_new = SymbolTable->capacity = SymbolTable->capacity * GROWTH_FACTOR;
        
        // re memory
        bucket_t** new_list = Calloc(capacity_new, sizeof(*new_list));

        for (size_t i = 0; i < capacity_old; i++) {
            bucket_t *currBucket = SymbolTable->BucketList[i];
            while (currBucket != NULL) {
                bucket_t *nextBucket = currBucket->next;
                unsigned short new_key = symboltable_hashcode(SymbolTable, currBucket->symbol);
                currBucket->next = new_list[new_key];
                new_list[new_key] = currBucket;
                currBucket = nextBucket;
            }
        }
        free(SymbolTable->BucketList);

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