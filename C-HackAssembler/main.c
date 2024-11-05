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
    //char wrongbuffer[100];
    int PC = 0; // set Program Counter to 0

    // first pass // remove white space, keep track of PC SYMBOLS

    while (condition != EOF) {
        // scan for word

        do {
            condition = fscanf(file_in, " %99[^ \n\t/]", buffer);
            if (condition == EOF) {
                exit(EXIT_SUCCESS);
            }
            
            if (condition == 0) {
                condition = fscanf(file_in, " %[^\n]", buffer);
            }

        } while (condition == 0);

        while (buffer[0] == '/') {
            condition = fscanf(file_in, " %[^\n]", buffer);
            if (condition == EOF) {
                exit(EXIT_SUCCESS);
            }
        }


        // if symbol is found, add to table
        if (buffer[0] == '(') {

            int symbol_len = 0;
            while (buffer[symbol_len] != ')') {
                symbol_len++;
            }
            char* symbol = malloc(symbol_len);
            if (symbol == NULL) { perror("error with symbol malloc"); exit(EXIT_FAILURE); }

            // from (LOOP) to LOOP
            for (int i = 0; i<symbol_len-1; i++) {
                symbol[i] = buffer[i+1];
            } symbol[symbol_len] = '\0';

            symboltable_set( SymbolTable, symbol, PC ); // add to symbol table

            free(symbol);

        // count up the Program counter
        } else {

            // remove comments after buffer
            char out_buffer[100] = {0};

            int j = 0;
            while (buffer[j] != '\0' && buffer[j] != ' ' && buffer[j] != '/' && buffer[j] != '\n') {
                out_buffer[j] = buffer[j];
                j++;
            }
            out_buffer[j] = '\0';

            fprintf(file_out, "%s\n", out_buffer);
            printf("%s\n", out_buffer);
            PC++;
        }

    }

    fclose(file_in);
    fclose(file_out);


    



    // second pass

    symboltable_destroy(BinaryTable);
    symboltable_destroy(SymbolTable);
}