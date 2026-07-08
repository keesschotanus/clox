#include <stdlib.h>

#include <collections/list/list.h>

#include "chunk.h"
#include "value.h"

void initChunk(Chunk *chunk)
{
	chunk->opcodes = list_create(100, sizeof(uint8_t));
	chunk->lines = list_create(100, sizeof(int));
	chunk->constants = list_create(100, sizeof(Value));
}

void freeChunk(Chunk *chunk)
{
	list_free(chunk->opcodes);
	list_free(chunk->lines);
	list_free(chunk->constants);
}
void writeChunk(Chunk *chunk, uint8_t byte, int line)
{
	list_append(chunk->opcodes, &byte);
	list_append(chunk->lines, &line);
}

int addConstant(Chunk *chunk, Value value)
{
	list_append(chunk->constants, &value);
	return (int)list_size(chunk->constants) - 1;
}
