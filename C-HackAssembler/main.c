#include "./SymbolTable/symbol_table.h"
#include "./Instructions/instructions.h"
#include <stdio.h>

int main(void) {
    symboltable_t *BinaryTable = C_binarytable_create();
    symboltable_t *SymbolTable = symboltable_init(100);
    symboltable_init_predefined_symbols(SymbolTable);
    
    FILE* file_in = fopen("in.asm", "r");
    if (file_in == NULL) { perror("error with opening file_in"); exit(EXIT_FAILURE); };
    FILE* file_out = fopen("out.asm", "w");
    if (file_out == NULL) { perror("error with opening file_out"); exit(EXIT_FAILURE); };

    int condition = 0;
    char buffer[100];
    int PC = 0; // set Program Counter to 0

    // first pass // remove white space, keep track of PC SYMBOLS

    while (condition != EOF) {

        // scan for word
        do {
            condition = fscanf(file_in, " %99[^ \n\t/]", buffer);
        } while (condition == 0);

        // if symbol is found, add to table
        if (buffer[0] == '(') {

            int symbol_len = 0;
            while (buffer[symbol_len] != ')') {
                symbol_len++;
            }
            char* symbol = malloc(symbol_len);
            if (symbol == NULL) { perror("error with symbol malloc"); exit(EXIT_FAILURE); }

            // from (LOOP) to LOOP
            for (int i = 0; i<symbol_len; i++) {
                symbol[i] = buffer[i+1];
            } symbol[symbol_len] = '\0';

            symboltable_set( SymbolTable, symbol, PC ); // add to symbol table

            free(symbol);

        // count up the Program counter
        } else {
            fprintf(file_out, "%s\n", buffer);
            PC++;
        }

    }

    fclose(file_in);
    fclose(file_out);


    



    // second pass

    symboltable_destroy(BinaryTable);
    symboltable_destroy(SymbolTable);
}