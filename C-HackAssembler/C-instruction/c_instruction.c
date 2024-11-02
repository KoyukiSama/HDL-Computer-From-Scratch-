#include "c_instruction.h"

symboltable_t* create_C_instruction_table() {
    // initialize BinaryTable
    symboltable_t* BinaryTable = symboltable_init(36);

    // set comp instructions
    symboltable_set(BinaryTable, "0", 21); // 0
    symboltable_set(BinaryTable, "1", 63); // 1
    symboltable_set(BinaryTable, "-1", 58); // -1
    symboltable_set(BinaryTable, "D", 12); // D
    symboltable_set(BinaryTable, "A", 48);
    symboltable_set(BinaryTable, "M", 112);
    symboltable_set(BinaryTable, "!D", 13); // !D
    symboltable_set(BinaryTable, "!A", 49);
    symboltable_set(BinaryTable, "!M", 113);
    symboltable_set(BinaryTable, "-D", 15); // -D
    symboltable_set(BinaryTable, "-A", 51);
    symboltable_set(BinaryTable, "-M", 115);
    symboltable_set(BinaryTable, "D+1", 31); // D+1
    symboltable_set(BinaryTable, "A+1", 55);
    symboltable_set(BinaryTable, "M+1", 119);
    symboltable_set(BinaryTable, "D-1", 14); // D-1
    symboltable_set(BinaryTable, "A-1", 50);
    symboltable_set(BinaryTable, "M-1", 114);
    symboltable_set(BinaryTable, "D+A", 2); // D+A
    symboltable_set(BinaryTable, "D+M", 66);
    symboltable_set(BinaryTable, "D-A", 19); // D-A
    symboltable_set(BinaryTable, "D-M", 83);
    symboltable_set(BinaryTable, "A-D", 7); // A-D
    symboltable_set(BinaryTable, "M-D", 71);
    symboltable_set(BinaryTable, "D&A", 0); // D&A
    symboltable_set(BinaryTable, "D&M", 64);
    symboltable_set(BinaryTable, "D|A", 21); // D|A
    symboltable_set(BinaryTable, "D|M", 85);

    // set dest instructions
    symboltable_set(BinaryTable, "null", 0); // null
    symboltable_set(BinaryTable, "M", 1); // M
    symboltable_set(BinaryTable, "D", 2); // D
    symboltable_set(BinaryTable, "MD", 3); // MD
    symboltable_set(BinaryTable, "A", 4); // A
    symboltable_set(BinaryTable, "AM", 5); // AM
    symboltable_set(BinaryTable, "AD", 6); // AD
    symboltable_set(BinaryTable, "AMD", 7); // AMD

    // set jump instructions
    symboltable_set(BinaryTable, "null", 0); // null
    symboltable_set(BinaryTable, "JGT", 1); // JGT
    symboltable_set(BinaryTable, "JEQ", 2); // JEQ
    symboltable_set(BinaryTable, "JGE", 3); // JGE
    symboltable_set(BinaryTable, "JLT", 4); // JLT
    symboltable_set(BinaryTable, "JNE", 5); // JNE
    symboltable_set(BinaryTable, "JLE", 6); // JLE
    symboltable_set(BinaryTable, "JMP", 7); // JMP

    return BinaryTable;
}

// helper function
void split_C_instruction(char* c_instruction, char* dest, char* comp, char* jump) {

    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char z = 0;
    unsigned char equalsPos = 0;
    unsigned char semiColonPos = 0;
    unsigned char terminatorPos = 0;

    while (c_instruction[i] != '\0') { // first pass, figure out the positions
        if (c_instruction[i] == '=') {
            equalsPos = i; // set 'equals'
        }
        else if (c_instruction[i] == ';') {
            semiColonPos = i; // set ';'
        }
        i++;
    } terminatorPos = i; // set '\0'
    i = 0; // reset i
    printf("equalsPos: %d\n", equalsPos);
    printf("semiColonPos: %d\n", semiColonPos);
    printf("terminatorPos: %d\n\n", terminatorPos);

    // second pass, assign the fields to dest, comp, jump strings
    if (equalsPos != 0) { // if dest field exists
        j = equalsPos;
        while (i < j) {
            dest[i] = c_instruction[i];
            i++;
        }
        dest[i] = 'z';
        i++;
    } else {
        dest = "null";
    }
    if (semiColonPos != 0) { // if jump field exists
        if (equalsPos != 0) {
            i = equalsPos + 1; // set i to start of comp string
        } else {
            i = 0;
        }

        j = semiColonPos;
        while (i < j) {
            comp[z] = c_instruction[i];
            i++;
            z++;
        }
        comp[z] = 'z';
        i++;

        z = 0;
        j = terminatorPos;
        while (i < j) {
            jump[z] = c_instruction[i];
            i++;
            z++;
        }
        jump[z] = 'z';
    } else {
        jump = "null";
    }
    if (semiColonPos == 0) { // if no jump field exists
        if (equalsPos != 0) {
            i = equalsPos + 1; // set i to start of comp string
        } else {
            i = 0;
        }

        j = terminatorPos;
        while (i < j) {
            comp[z] = c_instruction[i];
            i++;
            z++;
        }
        comp[i] = 'z';
    }
}

unsigned short translate_C_instruction_bin(symboltable_t* BinaryTable, char* c_instruction) {
    
    BinaryTable->capacity = 100;

    char dest[5] = {0};
    char comp[5] = {0};
    char jump[5] = {0};

    split_C_instruction(c_instruction, dest, comp, jump);
    // split up the c instruction into 3 strings, comp, dest, jump
    // translate each string to each binary value and shift the bits with the macros
    unsigned short bin_c_instruction = 0;
    bin_c_instruction += 1;

    return (unsigned short)(8);
}

// you have to initialize the binary table at the start of the 2nd pass
// else it'll be a waste of CPU