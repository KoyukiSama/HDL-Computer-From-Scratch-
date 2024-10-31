#pragma once

#include <stdlib.h>
#include <stdio.h>

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
 * @return, set value || error
 * @retval, value, if success, unsigned short
 * @retval, NULL, if fail
 */
void*           symboltable_set(symboltable_t *SymbolTable, char* symbol, unsigned short value);

/**
 *  !get value at symbol, in symboltable
 * 
 * @param SymbolTable, address
 * @param symbol, string
 * 
 * @return, value at symbol || error
 * @retval, value, if success, unsigned short
 * @retval, NULL, if fail
 */
void*           symboltable_get(symboltable_t *SymbolTable, char* symbol);