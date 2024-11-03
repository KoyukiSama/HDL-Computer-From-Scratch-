#include "./SymbolTable/symbol_table.h"
#include "./Instructions/instructions.h"
#include <stdio.h>

int main(void) {
    symboltable_t *BinaryTable = C_binarytable_create();

    char* instruction = "@34";
    char binary_string[17];
    instruction_to_bin(BinaryTable, instruction, binary_string);

    printf("instruction: %s\nbinary_string: %s", instruction, binary_string);

    symboltable_destroy(BinaryTable);
}