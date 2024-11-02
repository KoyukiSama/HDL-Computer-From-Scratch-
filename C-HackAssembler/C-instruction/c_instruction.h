#pragma once

// C-instruction shift MACRO
#define SHIFTBITS_OPCODE_111(bin_c_instruction) ((c_instruction) | (new_bits))
#define SHIFTBITS_COMPUTATION(bin_c_instruction, new_bits) ((c_instruction << 7) | (new_bits))
#define SHIFTBITS_DEST(bin_c_instruction, new_bits) ((c_instruction << 3) | (new_bits))
#define SHIFTBITS_JUMP(bin_c_instruction, new_bits) ((c_instruction << 3) | (new_bits))
