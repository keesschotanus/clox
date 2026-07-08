#include <collections/list/list.h>
#include <stdio.h>

#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(void)
{
	puts("Running clox...");

	Chunk chunk;
	initChunk(&chunk);

	int constant = addConstant(&chunk, 1.2);
	writeChunk(&chunk, OP_CONSTANT, 0);
	writeChunk(&chunk, (uint8_t)constant, 0);

	writeChunk(&chunk, OP_RETURN, 0);

	disassembleChunk(&chunk, "test chunk");

	freeChunk(&chunk);

	return 0;
}