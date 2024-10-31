#pragma once

#include <stdlib.h>

#define LOAD_FACTOR 0.75
#define GROWTH_FACTOR 2

// symbol-table data structure

typedef struct bucket {
    char* symbol;
    unsigned short value;
    struct bucket* next;
} bucket_t;

typedef struct symboltable {
    bucket_t** bucketlist;
    size_t size;
    size_t capacity;
} symboltable_t;

// symbol-table functions

/**
 *  !initialize symboltable
 *  
 * @param SymbolTable, address
 * @param initial_capacity, size_t
 * 
 * @returns Error code, char
 * @retval, 0, if success
 * @retval, -1, if fail
 * @retval, -2, if exists
*/
char            symboltable_init (symboltable_t *SymbolTable, size_t initial_capacity);

/**
 *  !destroy symboltable
 * 
 * @param SymbolTable, address
 * 
 * @returns Error code, char
 * @retval, 0, if success
 * @retval, -1, if fail
 */
char            symboltable_destroy (symboltable_t *SymbolTable);

/**
 *  !generate hashcode
 * 
 * @param SymbolTable, address
 * @param symbol, string
 * 
 * @return Hashcode(symbol), unsigned short
 * @retval, key
 */
unsigned short  symboltable_hashcode (symboltable_t *SymbolTable, char* symbol);

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
void*           symboltable_set (symboltable_t *SymbolTable, char* symbol, unsigned short value);

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
void*           symboltable_get (symboltable_t *SymbolTable, char* symbol);

// malloc handling