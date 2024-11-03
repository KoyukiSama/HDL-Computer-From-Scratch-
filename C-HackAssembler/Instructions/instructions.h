#pragma once

#include "../SymbolTable/symbol_table.h"

// C-instruction shift MACRO
#define SHIFTBITS_OPCODE_111(bin_c_instruction) ((unsigned short)(bin_c_instruction) | (111))
#define SHIFTBITS_COMPUTATION(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 7) | (new_bits))
#define SHIFTBITS_DEST(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 3) | (new_bits))
#define SHIFTBITS_JUMP(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 3) | (new_bits))


symboltable_t* C_binarytable_create();

void C_instruction_split(char* c_instruction, char* dest, char* comp, char* jump);

void C_instruction_to_bin(symboltable_t* BinaryTable, char* c_instruction, char* c_instruction_binary_string);
void A_instruction_to_bin(char* a_instruction, char* a_instruction_binary_string);

void instruction_to_bin(symboltable_t* BinaryTable, char* instruction, char* instruction_binary_string);