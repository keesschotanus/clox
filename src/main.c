#include <collections/list/list.h>
#include <stdio.h>

#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(void)
{
	initVM();

	Chunk chunk;
	initChunk(&chunk);

	int constant = addConstant(&chunk, 1.2);
	writeChunk(&chunk, OP_CONSTANT, 0);
	writeChunk(&chunk, (uint8_t)constant, 0);

	constant = addConstant(&chunk, 3.4);
	writeChunk(&chunk, OP_CONSTANT, 123);
	writeChunk(&chunk, (uint8_t)constant, 123);
	
	writeChunk(&chunk, OP_ADD, 123);

	constant = addConstant(&chunk, 5.6);
	writeChunk(&chunk, OP_CONSTANT, 0);
	writeChunk(&chunk, (uint8_t)constant, 0);

	writeChunk(&chunk, OP_DIVIDE, 0);

	writeChunk(&chunk, OP_NEGATE, 0);

	writeChunk(&chunk, OP_RETURN, 0);

	interpret(&chunk);
	freeVM();
	freeChunk(&chunk);

	return 0;
}