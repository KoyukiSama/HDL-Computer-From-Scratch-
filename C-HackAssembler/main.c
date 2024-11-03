#include "./SymbolTable/symbol_table.h"
#include "./C-instruction/c_instruction.h"
#include <stdio.h>

int main(void) {
    symboltable_t *BinaryTable = C_binarytable_create();

    char* c_instruction = "MD=D+M;JMP";

    C_instruction_to_bin(BinaryTable, c_instruction);
}