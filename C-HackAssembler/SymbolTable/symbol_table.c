#include "symbol_table.h"

char symboltable_init (symboltable_t *SymbolTable, size_t initial_capacity) {
    if (SymbolTable != NULL) {
        return 2;
    }
}

char symboltable_destroy (symboltable_t *SymbolTable);

unsigned short  symboltable_hashcode (symboltable_t *SymbolTable, char* symbol);

void* symboltable_set (symboltable_t *SymbolTable, char* symbol, unsigned short value);

void* symboltable_get (symboltable_t *SymbolTable, char* symbol);