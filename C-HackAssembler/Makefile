CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

TARGET = a.out

SOURCES = main.c ./SymbolTable/symbol_table.c ./Instructions/instructions.c

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)