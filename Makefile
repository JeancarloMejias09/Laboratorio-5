CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/arreglo_dinamico_lab.c src/main.c
EXEC = programa_lab5

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXEC)

.PHONY: all clean
