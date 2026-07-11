SRC_DIR = src
INC_DIR = include
BLD_DIR = build

CC = gcc
CFLAGS = -std=c2x -g -O0 -Wall -Wextra -I$(INC_DIR)

objects = $(BLD_DIR)/main.o \
	$(BLD_DIR)/chunk.o \
	$(BLD_DIR)/compiler.o \
	$(BLD_DIR)/debug.o \
	$(BLD_DIR)/scanner.o \
	$(BLD_DIR)/value.o \
	$(BLD_DIR)/vm.o 

# Include collections library
SYSTEM_COLL_PREFIX ?= /usr/local
COLL_LIB_DIR := $(SYSTEM_COLL_PREFIX)/lib
COLL_INC := -I$(SYSTEM_COLL_PREFIX)/include
COLL_STATIC := $(COLL_LIB_DIR)/libcollections.a

LDLIBS = -L$(COLL_LIB_DIR) -lcollections
CFLAGS += -I$(INC_DIR) $(COLL_INC)

clox: $(BLD_DIR) $(objects)
	$(CC) $(CFLAGS) -o $(BLD_DIR)/clox $(objects) $(LDLIBS)

$(BLD_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/common.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)/compiler.o: $(SRC_DIR)/compiler.c $(INC_DIR)/compiler.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)/chunk.o: $(SRC_DIR)/chunk.c $(INC_DIR)/chunk.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)/debug.o: $(SRC_DIR)/debug.c $(INC_DIR)/debug.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)/scanner.o: $(SRC_DIR)/scanner.c $(INC_DIR)/scanner.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)/value.o: $(SRC_DIR)/value.c $(INC_DIR)/value.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR)/vm.o: $(SRC_DIR)/vm.c $(INC_DIR)/vm.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR):
	mkdir -p $(BLD_DIR)

clean:
	rm -f $(wildcard $(BLD_DIR))/*.o
	rm -f $(BLD_DIR)/clox

.PHONY: clean
