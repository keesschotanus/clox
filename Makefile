SRC_DIR = src
INC_DIR = include
BLD_DIR = build

CC = gcc
CFLAGS = -std=c2x -g -O0 -Wall -Wextra -I$(INC_DIR)

objects = $(BLD_DIR)/main.o $(BLD_DIR)/debug.o

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

$(BLD_DIR)/debug.o: $(SRC_DIR)/debug.c $(INC_DIR)/debug.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BLD_DIR):
	mkdir -p $(BLD_DIR)

clean:
	rm -f $(wildcard $(BLD_DIR))/*.o
	rm -f $(BLD_DIR)/clox

.PHONY: clean
