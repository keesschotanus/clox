SRC_DIR = src
INC_DIR = include
BLD_DIR = build

CC = gcc
CFLAGS = -std=c2x -g -O0 -Wall -Wextra -I$(INC_DIR)

objects = $(BLD_DIR)/main.o

clox: $(BLD_DIR) $(objects)
	$(CC) $(CFLAGS) -o $(BLD_DIR)/clox $(objects)

$(BLD_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/common.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR):
	mkdir -p $(BLD_DIR)

clean:
	rm -f $(wildcard $(BLD_DIR))/*.o
	rm -f $(BLD_DIR)/clox

.PHONY: clean
