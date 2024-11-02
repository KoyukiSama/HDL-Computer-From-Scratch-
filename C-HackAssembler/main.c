#include "./SymbolTable/symbol_table.h"
#include <stdio.h>

int main(void) {
    symboltable_t* SymbolTable = symboltable_init(4);

    char a1 = symboltable_set(SymbolTable, "hello", 15);
    printf("%i\n", a1);
    char a2 = symboltable_set(SymbolTable, "hello", 15);
    printf("%i\n", a2);
    unsigned short short1;
    char a3 = symboltable_get(SymbolTable, "hello", &short1);
    printf("get: %d, %i\n\n", short1, a3);
    

    char b1 = symboltable_set(SymbolTable, "ben", 40);
    printf("%i\n", b1);
    char b2 = symboltable_set(SymbolTable, "ben", 40);
    printf("%i\n", b2);
    unsigned short short2;
    char b3 = symboltable_get(SymbolTable, "ben", &short2);
    printf("get: %d, %i\n\n", short2, b3);

    char c1 = symboltable_set(SymbolTable, "kaboji", 150);
    printf("%i\n", c1);
    char c2 = symboltable_set(SymbolTable, "kaboji", 150);
    printf("%i\n", c2);
    unsigned short short3;
    char c3 = symboltable_get(SymbolTable, "kaboji", &short3);
    printf("get: %d, %i\n\n", short3, c3);

    char d1 = symboltable_set(SymbolTable, "zetta", 500);
    printf("%i\n", d1);
    char d2 = symboltable_set(SymbolTable, "zetta", 300);
    printf("%i\n", d2);
    unsigned short short4;
    char d3 = symboltable_get(SymbolTable, "zetta", &short4);
    printf("get: %d, %i\n\n", short4, d3);

    char e1 = symboltable_set(SymbolTable, "balle", 700);
    printf("%i\n", e1);
    char e2 = symboltable_set(SymbolTable, "balle", 400);
    printf("%i\n", e2);
    unsigned short short5;
    char e3 = symboltable_get(SymbolTable, "balle", &short5);
    printf("get: %d, %i\n\n", short5, e3);

    char f1 = symboltable_set(SymbolTable, "bomer", 700);
    printf("%i\n", f1);
    char f2 = symboltable_set(SymbolTable, "bomer", 400);
    printf("%i\n", f2);
    unsigned short short6;
    char f3 = symboltable_get(SymbolTable, "bomer", &short6);
    printf("get: %d, %i\n\n", short6, f3);

    char h1 = symboltable_set(SymbolTable, "zopper", 700);
    printf("%i\n", h1);
    char h2 = symboltable_set(SymbolTable, "zopper", 400);
    printf("%i\n", h2);
    unsigned short short7;
    char h3 = symboltable_get(SymbolTable, "zopper", &short7);
    printf("get: %d, %i\n\n", short7, h3);

    char g1 = symboltable_set(SymbolTable, "klopper", 700);
    printf("%i\n", g1);
    char g2 = symboltable_set(SymbolTable, "klopper", 400);
    printf("%i\n", g2);
    unsigned short short8;
    char g3 = symboltable_get(SymbolTable, "klopper", &short8);
    printf("get: %d, %i\n\n", short8, g3);

    symboltable_destroy(SymbolTable);
    printf("All tests passed successfully.\n");
    return 0;
}