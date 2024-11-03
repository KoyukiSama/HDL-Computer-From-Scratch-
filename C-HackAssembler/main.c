#include "./SymbolTable/symbol_table.h"
#include "./C-instruction/c_instruction.h"
#include <stdio.h>

int main(void) {
    symboltable_t *BinaryTable = binarytable_create();

    char* command1 = "MD=D+M;JMP\n";
    printf("%s", command1);
    unsigned short dec_c_instruction1 = C_instruction_to_bin(BinaryTable, command1);
    printf("decimal: %d\n", dec_c_instruction1);

    char* command2 = "D+M\n";
    printf("%s", command2);
    unsigned short dec_c_instruction2 = C_instruction_to_bin(BinaryTable, command2);
    printf("decimal: %d\n", dec_c_instruction2);

    symboltable_destroy(BinaryTable);
}