#pragma once

#include "../SymbolTable/symbol_table.h"

// C-instruction shift MACRO
#define SHIFTBITS_OPCODE_111(bin_c_instruction) ((unsigned short)(bin_c_instruction) | (111))
#define SHIFTBITS_COMPUTATION(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 7) | (new_bits))
#define SHIFTBITS_DEST(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 3) | (new_bits))
#define SHIFTBITS_JUMP(bin_c_instruction, new_bits) (unsigned short)((bin_c_instruction << 3) | (new_bits))


symboltable_t* create_C_instruction_table();

void split_C_instruction(char* c_instruction, char* dest, char* comp, char* jump);

unsigned short translate_C_instruction_bin(symboltable_t* BinaryTable, char* c_instruction);