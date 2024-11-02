#include "./SymbolTable/symbol_table.h"
#include "./C-instruction/c_instruction.h"
#include <stdio.h>

int main(void) {
    char c_instruct[] = "M=D+1;null";

    char dest[5] = "";
    char comp[5] = "";
    char jump[5] = "";

    split_C_instruction(c_instruct, dest, comp, jump);

    printf("%s\n%s\n%s\n%s\n", c_instruct, dest, comp, jump);
}