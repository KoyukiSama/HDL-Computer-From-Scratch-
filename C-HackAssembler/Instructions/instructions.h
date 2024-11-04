#pragma once

#include "../SymbolTable/symbol_table.h"

// C-instruction shift MACRO
#define SHIFTBITS_OPCODE_111(bin_c_instruction) ((unsigned short)(bin_c_instruction) | (111))
#define SHIFTBITS_COMPUTATION(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 7) | (new_bits))
#define SHIFTBITS_DEST(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 3) | (new_bits))
#define SHIFTBITS_JUMP(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 3) | (new_bits))


// instruction to binary string functions

/**
 *  !initialize binary table, creates the predefined binarytable for c-instructions
 *  !has to be freed later by the user!
 * 
 * @returns symboltable_t *
 * 
 */
symboltable_t* C_binarytable_create();

/**
 *  !parses the c instruction into dest, comp and jump fields
 * 
 * @param c_instruction, represents the c_instruction string
 * @param dest, represents the destination return param
 * @param comp, represents the computation return param
 * @param jump, represents the jump return param
 */
void C_instruction_split(char* c_instruction, char* dest, char* comp, char* jump);

/**
 *  !translates the C instruction to binary
 * 
 * @param BinaryTable, represents the predefined binary table that has to be created with C_binarytable_create();
 * @param c_instruction, represents c_instruction string
 * @param c_instruction_binary_string, represents the c_instruction into a string of chars, that represents the binary display, not actual binary
 */
void C_instruction_to_bin(symboltable_t* BinaryTable, char* c_instruction, char* c_instruction_binary_string);

/**
 *  !translates the A instruction to binary
 * 
 * @param a_instruction, represents a_instruction string
 * @param a_instruction_binary_string, represents the a_instruction into a string of chars, that represents the binary display, not actual binary
 */
void A_instruction_to_bin(char* a_instruction, char* a_instruction_binary_string);

/**
 *  !translates the A OR C instruction to binary, the command will know 
 *  !if it's a variable, this part does not take care of it, you have to first preprocess the variable into it's number so from, @variable -> @16, so it only takes @numbers as A instructions.
 * 
 * @param BinaryTable, represents the predefined binary table that has to be created with C_binarytable_create();
 * @param instruction, represents instruction string
 * @param instruction_binary_string, represents the instruction into a string of chars, that represents the binary display, not actual binary
 */
void instruction_to_bin(symboltable_t* BinaryTable, char* instruction, char* instruction_binary_string);