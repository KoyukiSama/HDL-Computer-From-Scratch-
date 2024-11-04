#include "./SymbolTable/symbol_table.h"
#include "./Instructions/instructions.h"
#include <stdio.h>

int main(void) {
    symboltable_t *BinaryTable = C_binarytable_create();
    symboltable_t *SymbolTable = symboltable_init(100);
    symboltable_init_predefined_symbols(SymbolTable);

    // first pass // remove white space, keep track of PC SYMBOLS




    // second pass

    symboltable_destroy(BinaryTable);
    symboltable_destroy(SymbolTable);
}