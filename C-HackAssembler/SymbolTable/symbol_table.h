#pragma once

#include <stdlib.h>

#define LOAD_FACTOR 0.75
#define GROWTH_FACTOR 2

// symbol-table data structure

typedef struct bucket {
    char* symbol;
    short value;
    struct bucket* next;
} bucket_t;

typedef struct symboltable {
    bucket_t** bucketlist;
    size_t size;
    size_t capacity;
} symboltable_t;

// symbol-table functions

/**
 *  initialize symboltable
 *  
 * @param SymbolTable, address of symboltable
 * @param initial_capacity, initial_capacity of symboltable
 * 
 * @returns, error code
 * @retval, 0, if success
 * @retval, -1, if fail
*/
char            symboltable_init (symboltable_t *SymbolTable, size_t initial_capacity);

/**
 *  
 */
char            symboltable_destroy (symboltable_t *SymbolTable);

unsigned short  symboltable_hashcode (symboltable_t *SymbolTable, char* symbol);

void*           symboltable_set (symboltable_t *SymbolTable, char* symbol, unsigned short value);
void*           symboltable_get (symboltable_t *SymbolTable, char* symbol);

// malloc handling