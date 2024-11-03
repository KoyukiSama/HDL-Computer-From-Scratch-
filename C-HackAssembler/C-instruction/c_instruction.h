#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LOAD_FACTOR 0.75
#define GROWTH_FACTOR 2

// binary-table data structure

typedef struct bucket {
    char* instruction_string;
    char* instruction_binary;
    struct bucket* next;
} bucket_t;

typedef struct binarytable {
    bucket_t** BucketList;
    size_t size;
    size_t capacity;
} binarytable_t;

// symbol-table functions

/**
 *  !initialize symboltable
 *  
 * @param initial_capacity, size_t
 * 
 * @returns symboltable
*/
binarytable_t*  binarytable_init();

/**
 *  !destroy symboltable
 * 
 * @param SymbolTable, address
 */
void            binarytable_destroy(binarytable_t *BinaryTable);

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
char            binarytable_set(binarytable_t *BinaryTable, const char* instruction_string, char* instruction_binary);

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
char           binarytable_get(binarytable_t *BinaryTable, const char* instruction_string, char* instruction_binary);


// helper functions 

void binarytable_ensure_capacity(binarytable_t *BinaryTable);
unsigned short  binarytable_hashcode(binarytable_t *BinaryTable, const char* instruction_string);
void* Malloc(size_t size_t);
void* Calloc(size_t nmemb, size_t size);
void* CallocExit(size_t nmemb, size_t size);
void* MallocExit(size_t size_t);


binarytable_t* binarytable_create();

void C_instruction_split(char* c_instruction, char* dest, char* comp, char* jump);

unsigned short C_instruction_bin_translate(binarytable_t* BinaryTable, char* c_instruction);