#pragma once

// C-instruction shift MACRO
#define SHIFTBITS_OPCODE_111(c_instruction) ((c_instruction) | (new_bits))
#define SHIFTBITS_COMPUTATION(c_instructionvalue, new_bits) ((c_instruction << 7) | (new_bits))
#define SHIFTBITS_DEST(c_instructionvalue, new_bits) ((c_instruction << 3) | (new_bits))
#define SHIFTBITS_JUMP(c_instructionvalue, new_bits) ((c_instruction << 3) | (new_bits))
