#include "./SymbolTable/symbol_table.h"
#include "./C-instruction/c_instruction.h"
#include <stdio.h>

int main(void) {
    symboltable_t *BinaryTable = create_C_instruction_table();

    unsigned short dec_c_instruction = translate_C_instruction_bin(BinaryTable, "MD=D+M;JMP");

    printf("decimal: %d", dec_c_instruction);
}