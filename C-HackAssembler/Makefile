CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

TARGET = test_symboltable

SOURCES = main.c ./SymbolTable/symbol_table.c

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)