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

    // set dest instructions
    symboltable_set(BinaryTable, "null", "0b000"); // null
    symboltable_set(BinaryTable, "M", "0b001"); // M
    symboltable_set(BinaryTable, "D", "0b010"); // D
    symboltable_set(BinaryTable, "MD", "0b011"); // MD
    symboltable_set(BinaryTable, "A", "0b100"); // A
    symboltable_set(BinaryTable, "AM", "0b101"); // AM
    symboltable_set(BinaryTable, "AD", "0b110"); // AD
    symboltable_set(BinaryTable, "AMD", "0b111"); // AMD

    // set jump instructions
    symboltable_set(BinaryTable, "null", "0b000"); // null
    symboltable_set(BinaryTable, "JGT", "0b001"); // JGT
    symboltable_set(BinaryTable, "JEQ", "0b010"); // JEQ
    symboltable_set(BinaryTable, "JGE", "0b011"); // JGE
    symboltable_set(BinaryTable, "JLT", "0b100"); // JLT
    symboltable_set(BinaryTable, "JNE", "0b101"); // JNE
    symboltable_set(BinaryTable, "JLE", "0b110"); // JLE
    symboltable_set(BinaryTable, "JMP", "0b111"); //JMP
}