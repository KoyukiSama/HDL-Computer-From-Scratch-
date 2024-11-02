#include "c_instruction.h"
#include "../SymbolTable/symbol_table.h"

unsigned short translate_Comp_Binary(symboltable_t* BinaryTable, char* strComp) {
    
}

symboltable_t* create_C_instruction_table() {
    // initialize BinaryTable
    symboltable_t* BinaryTable = symboltable_init(36);

    // set comp instructions
    symboltable_set(BinaryTable, "0", 0b0101010); // 0
    symboltable_set(BinaryTable, "1", 0b0111111); // 1
    symboltable_set(BinaryTable, "-1", 0b0111010); // -1
    symboltable_set(BinaryTable, "D", 0b0001100); // D
    symboltable_set(BinaryTable, "A", 0b0110000);
    symboltable_set(BinaryTable, "M", 0b1110000);
    symboltable_set(BinaryTable, "!D", 0b0001101); // !D
    symboltable_set(BinaryTable, "!A", 0b0110001);
    symboltable_set(BinaryTable, "!M", 0b1110001);
    symboltable_set(BinaryTable, "-D", 0b0001111); // -D
    symboltable_set(BinaryTable, "-A", 0b0110011);
    symboltable_set(BinaryTable, "-M", 0b1110011);
    symboltable_set(BinaryTable, "D+1", 0b0011111); // D+1
    symboltable_set(BinaryTable, "A+1", 0b0110111);
    symboltable_set(BinaryTable, "M+1", 0b1110111);
    symboltable_set(BinaryTable, "D-1", 0b0001110); // D-1
    symboltable_set(BinaryTable, "A-1", 0b0110010);
    symboltable_set(BinaryTable, "M-1", 0b1110010);
    symboltable_set(BinaryTable, "D+A", 0b0000010); // D+A
    symboltable_set(BinaryTable, "D+M", 0b1000010);
    symboltable_set(BinaryTable, "D-A", 0b0010011); // D-A
    symboltable_set(BinaryTable, "D-M", 0b1010011);
    symboltable_set(BinaryTable, "A-D", 0b0000111); // A-D
    symboltable_set(BinaryTable, "M-D", 0b1000111);
    symboltable_set(BinaryTable, "D&A", 0b0000000); // D&A
    symboltable_set(BinaryTable, "D&M", 0b1000000);
    symboltable_set(BinaryTable, "D|A", 0b0010101); // D|A
    symboltable_set(BinaryTable, "D|M", 0b1010101);

}