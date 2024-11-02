#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LOAD_FACTOR 0.75
#define GROWTH_FACTOR 2

// symbol-table data structure

typedef struct bucket {
    char* symbol;
    unsigned short value;
    struct bucket* next;
} bucket_t;

typedef struct symboltable {
    bucket_t** BucketList;
    size_t size;
    size_t capacity;
} symboltable_t;

// symbol-table functions

/**
 *  !initialize symboltable
 *  
 * @param initial_capacity, size_t
 * 
 * @returns symboltable
*/
symboltable_t*  symboltable_init(size_t initial_capacity);

/**
 *  !destroy symboltable
 * 
 * @param SymbolTable, address
 */
void            symboltable_destroy(symboltable_t *SymbolTable);

/**
 *  !set symbol-value pair, in symboltable
 * 
 * @param SymbolTable, address
 * @param symbol, string
 * @param value, unsigned short
 * 
 * @return, exist or success
 * @retval, 0, if success
 * @retval, -1, if already exists
 */
char            symboltable_set(symboltable_t *SymbolTable, const char* symbol, unsigned short value);

/**
 *  !get value at symbol, in symboltable
 * 
 * @param SymbolTable, address
 * @param symbol, string
 * 
 * @return, error code
 * @retval, 0 if exists
 * @retval, -1 if not in table
 */
char           symboltable_get(symboltable_t *SymbolTable, const char* symbol, unsigned short *out_value);


// helper functions 

void symboltable_ensure_capacity(symboltable_t *SymbolTable);
unsigned short  symboltable_hashcode(symboltable_t *SymbolTable, const char* symbol);
void* Malloc(size_t size_t);
void* Calloc(size_t nmemb, size_t size);
void* CallocExit(size_t nmemb, size_t size);
void* MallocExit(size_t size_t);