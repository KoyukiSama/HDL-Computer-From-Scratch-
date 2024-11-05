// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

// vars
// @end_screen
// @start_screen
// @curr
@24575
D=A
@end_screen             
M=D                     // set start screen to 17203
@16384
D=A
@start_screen           
M=D                     // set start screen to 16384
@curr
M=D                     // set curr to start screen


// key press check ---------------------KEY---KEY------KEY----KEY-----------------------------------------
(START)
(CHECK_KEYPRESS) // if key NEQ
@24576
D=M
@BLACK_LOOP
D;JNE // if black == 1 -----------------KEY---KEY------KEY----KEY-------------------------------------------
//
//
//
//
//
//
//
// white loop -------------------WHITE---WHITE------WHITE----WHITE-----------------------------------------
(WHITE_LOOP)
@curr
D=M
@start_screen
D=D-M //                comp to start screen
@CHECK_WHITE_OUTBOUND
D;JGE //                else {

@start_screen
D=M
@curr
M=D             // curr = start_screen
@START
0;JMP           // jump start

// }
(CHECK_WHITE_OUTBOUND) // if curr >= start_screen {

@curr
A=M
M=0 // set the bit at currPtr to 0
@curr
M=M-1 // set ptr to previous location


@24576
D=M
@WHITE_LOOP
D;JEQ // if white == 1

@START
0;JMP // if white == 0 -----------WHITE---WHITE------WHITE----WHITE--------------------------------------------
//
//
//
//
//
//
//
// black loop -----------------BLACK----BLACK-------BLACK--------BLACK--------------------------------------------------
(BLACK_LOOP)

@curr
D=M
@end_screen
D=D-M //                comp to end screen
@CHECK_BLACK_OUTBOUND
D;JLE //                else {

@end_screen
D=M
@curr
M=D             // curr = end_screen
@START
0;JMP           // jump start

// }
(CHECK_BLACK_OUTBOUND) // if curr >= start_screen {

@curr
A=M
D=0 // set the bit at currPtr to 0
M=!D // negate 0 to 1
@curr
M=M+1 // set ptr to previous location


@24576
D=M
@BLACK_LOOP
D;JNE // if black == 1 

@START
0;JMP // go back to start --------BLACK----BLACK-------BLACK--------BLACK-----------------------------------


