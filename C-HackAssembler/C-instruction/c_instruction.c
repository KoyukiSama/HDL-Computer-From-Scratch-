#include "c_instruction.h"

binarytable_t* binarytable_create() {
    // initialize BinaryTable
    binarytable_t* BinaryTable = binarytable_init();

    // set comp instructions
    binarytable_set(BinaryTable, "0", "0101010"); // 0
    binarytable_set(BinaryTable, "1", "0111111"); // 1
    binarytable_set(BinaryTable, "-1", "0111010"); // -1
    binarytable_set(BinaryTable, "D", "0001100"); // D
    binarytable_set(BinaryTable, "A", "0110000");
    binarytable_set(BinaryTable, "M", "1110000");
    binarytable_set(BinaryTable, "!D", "0001101"); // !D
    binarytable_set(BinaryTable, "!A", "0110001");
    binarytable_set(BinaryTable, "!M", "1110001");
    binarytable_set(BinaryTable, "-D", "0001111"); // -D
    binarytable_set(BinaryTable, "-A", "0110011");
    binarytable_set(BinaryTable, "-M", "1110011");
    binarytable_set(BinaryTable, "D+1", "0011111"); // D+1
    binarytable_set(BinaryTable, "A+1", "0110111");
    binarytable_set(BinaryTable, "M+1", "1110111");
    binarytable_set(BinaryTable, "D-1", "0001110"); // D-1
    binarytable_set(BinaryTable, "A-1", "0110010");
    binarytable_set(BinaryTable, "M-1", "1110010");
    binarytable_set(BinaryTable, "D+A", "0000010"); // D+A
    binarytable_set(BinaryTable, "D+M", "1000010");
    binarytable_set(BinaryTable, "D-A", "0010011"); // D-A
    binarytable_set(BinaryTable, "D-M", "1010011");
    binarytable_set(BinaryTable, "A-D", "0000111"); // A-D
    binarytable_set(BinaryTable, "M-D", "1000111");
    binarytable_set(BinaryTable, "D&A", "0000000"); // D&A
    binarytable_set(BinaryTable, "D&M", "1000000");
    binarytable_set(BinaryTable, "D|A", "0010101"); // D|A
    binarytable_set(BinaryTable, "D|M", "1010101");

    // set dest instructions
    binarytable_set(BinaryTable, "null", "000"); // null
    binarytable_set(BinaryTable, "M", "001"); // M
    binarytable_set(BinaryTable, "D", "010"); // D
    binarytable_set(BinaryTable, "MD", "011"); // MD
    binarytable_set(BinaryTable, "A", "100"); // A
    binarytable_set(BinaryTable, "AM", "101"); // AM
    binarytable_set(BinaryTable, "AD", "110"); // AD
    binarytable_set(BinaryTable, "AMD", "111"); // AMD

    // set jump instructions
    binarytable_set(BinaryTable, "null", "000"); // null
    binarytable_set(BinaryTable, "JGT", "001"); // JGT
    binarytable_set(BinaryTable, "JEQ", "010"); // JEQ
    binarytable_set(BinaryTable, "JGE", "011"); // JGE
    binarytable_set(BinaryTable, "JLT", "100"); // JLT
    binarytable_set(BinaryTable, "JNE", "101"); // JNE
    binarytable_set(BinaryTable, "JLE", "110"); // JLE
    binarytable_set(BinaryTable, "JMP", "111"); // JMP

    return BinaryTable;
}

// helper function
void C_instruction_split(char* c_instruction, char* dest, char* comp, char* jump) {

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

    // second pass, assign the fields to dest, comp, jump strings
    if (equalsPos != 0) { // if dest field exists
        j = equalsPos;
        while (i < j) {
            dest[i] = c_instruction[i];
            i++;
        }
        dest[i] = '\0';
        i++;
    } else {
        dest[0] = 'n'; dest[1] = 'u'; dest[2] = 'l'; dest[3] = 'l'; dest[4] = '\0';
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
        comp[z] = '\0';
        i++;

        z = 0;
        j = terminatorPos;
        while (i < j) {
            jump[z] = c_instruction[i];
            i++;
            z++;
        }
        jump[z] = '\0';
    } else {
        jump[0] = 'n'; jump[1] = 'u'; jump[2] = 'l'; jump[3] = 'l'; jump[4] = '\0';
    }
    if (semiColonPos == 0) { // if no jump field exists
        if (equalsPos != 0) {
            i = equalsPos + 1; // set i to start of comp string
        } else {
            i = 0;
        }

        z = 0;
        j = terminatorPos;
        while (i < j) {
            comp[z] = c_instruction[i];
            i++;
            z++;
        }
        comp[z] = '\0';
    }
}

char* C_instruction_to_bin(binarytable_t* BinaryTable, char* c_instruction) {
    
    char dest[5] = {0};
    char comp[5] = {0};
    char jump[5] = {0};
    
    char* translated_bits_comp; 
    char* translated_bits_dest;
    char* translated_bits_jump;
    
    // split the c-instruction
    C_instruction_split(c_instruction, dest, comp, jump); 
    
    // translate to binary
    binarytable_get(BinaryTable, comp, translated_bits_comp);
    binarytable_get(BinaryTable, dest, translated_bits_dest);
    binarytable_get(BinaryTable, jump, translated_bits_jump);

    // concat the strings together
    char translated_bits_concat[16] = {'1', '1', '1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\0'};

    int i = 3, j = 0;
    while (translated_bits_comp[j] != '\0') {
        translated_bits_concat[i] = translated_bits_comp[j];
        i++;
        j++;
    } j = 0;
    while (translated_bits_dest[j] != '\0') {
        translated_bits_concat[i] = translated_bits_dest[j];
        i++;
        j++;
    } j = 0;
    while (translated_bits_jump[j] != '\0') {
        translated_bits_concat[i] = translated_bits_jump[j];
        i++;
        j++;
    }
    
    return translated_bits_concat;
}

// you have to initialize the binary table at the start of the 2nd pass
// else it'll be a waste of CPU