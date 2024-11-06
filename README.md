# HDL-Computer-From-Scratch-
Here I built my virtual computer from scratch with HDL, I did this while watching the nand2tetris course.

I also tried making the look-ahead-carry-adder component for a 16BIT adder but the IDE did not allow me to write it efficiently and forced me to write it in elementry gates, so halfway through I quit since my PC could not handle it.

## Contained in repo:

- The hack PC
- 2 programs written hack assembly

### the Hack PC that I built. 
Some components I did not build like a screen and keyboard drivers.

I also tried making the look-ahead-carry-adder component for a 16BIT adder but the IDE did not allow me to write it efficiently and forced me to write it in elementry gates, so halfway through I quit since my PC could not handle it.

Hack PC
- CPU from scratch
- RAM from scratch

The Ram and CPU
- Memory Gates      (mostly for RAM but the registers also for CPU)
- Arithmetic Gates  (mostly in CPU)
- Elementary Gates  (for everything)

### Hack Assembly programs I wrote

- Mult.asm
    multiplies 2 numbers with each other. (39 lines of code to write in ASM)

- Fill.asm
    if key pressed -> blackens screen
    no key pressed -> whitens screen
    (105 lines of code to write in ASM)


### Hack Assembler in C

- main.c has 2 steps, 
    first it gets rid of all the garbage and cleans it up nicely, preprocessing
    secondly it translates all the instructions to binary code.

- Instruction/
    this directory has the library that I made,
    it has the code for the translation logic.

- SymbolTable/
    this directory has the hashmap library that I made,
    it has the code for hashmap logic


### Known issues

sadly there was an error that I could not fix with huge files,
the error has something to do with fclose not working properly.

