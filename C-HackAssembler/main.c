#include "./SymbolTable/symbol_table.h"
#include "./C-instruction/c_instruction.h"
#include <stdio.h>

int main(void) {
    char c_instruct[] = "MD=D-1;JMP";

    char dest[5] = {0};
    char comp[5] = {0};
    char jump[5] = {0};

    split_C_instruction(c_instruct, dest, comp, jump);

    printf("%s\n%s\n%s\n%s\n", c_instruct, dest, comp, jump);
}