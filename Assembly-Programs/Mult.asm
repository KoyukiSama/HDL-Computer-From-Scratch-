// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// The algorithm is based on repetitive addition.

@R2
M=0 // initialise R2

// Check if R0 or R1 is 0
@R0
D=M        // Load R0 into D
@WAS0
D;JEQ      // Jump to WAS0 if R0 == 0

@R1
D=M        // Load R1 into D
@WAS0
D;JEQ

(LOOP)

@R0
D=M // D = R0
@R2
M=D+M // Add previous R2 = R0 + R2

@R1
D=M-1 // D = R1 - 1
M=D // decrement R1 = R1 - 1

@LOOP
D;JGT // D != 0 ?

(END)
@END
0;JMP

(WAS0)
@0
D=A
@2
M=D // set R2 to 0
@END
0;JMP

