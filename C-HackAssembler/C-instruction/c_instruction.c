#include "c_instruction.h"

binarytable_t* create_C_instruction_table() {
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

unsigned short translate_C_instruction_bin(binarytable_t* BinaryTable, char* c_instruction) {
    
    char dest[5] = {0};
    char comp[5] = {0};
    char jump[5] = {0};
    
    // init binary instruction
    unsigned short bin_c_instruction = 0; 
    
    // translate string instructions to binary instructions
    unsigned short translated_comp_bits; 
    unsigned short translated_dest_bits;
    unsigned short translated_jump_bits;
    binarytable_get(BinaryTable, comp, &translated_comp_bits);
    binarytable_get(BinaryTable, dest, &translated_dest_bits);
    binarytable_get(BinaryTable, jump, &translated_jump_bits);
    
    // split the c-instruction
    split_C_instruction(c_instruction, dest, comp, jump); 
    
    // shift bits into one binary number
    bin_c_instruction = SHIFTBITS_OPCODE_111(bin_c_instruction);
    bin_c_instruction = SHIFTBITS_COMPUTATION(bin_c_instruction, translated_comp_bits); // comp bits
    bin_c_instruction = SHIFTBITS_DEST(bin_c_instruction, translated_dest_bits); // dest bits
    bin_c_instruction = SHIFTBITS_JUMP(bin_c_instruction, translated_jump_bits); // jump bits

    for (int i = 15; i>=0; i--) {
        putchar((bin_c_instruction & (1U << i)) ? '1' : '0');
    }
    putchar('\n');

    return bin_c_instruction;
}

// you have to initialize the binary table at the start of the 2nd pass
// else it'll be a waste of CPU