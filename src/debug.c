#include <stdio.h>

#include <collections/list/list.h>

#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *name)
{
	printf("== %s ==\n", name);

	for (int offset = 0; offset < (int)list_size(chunk->opcodes);)
	{
		offset = disassembleInstruction(chunk, offset);
	}
}

static int constantInstruction(const char *name, Chunk *chunk, int offset)
{
	uint8_t constant = *(const uint8_t *)list_get(chunk->opcodes, offset + 1);
	printf("%-16s %4d '", name, constant);
	printValue(*(const Value *)list_get(chunk->constants, constant));
	printf("'\n");
	return offset + 2;
}

static int simpleInstruction(const char *name, int offset)
{
	printf("%s\n", name);
	return offset + 1;
}

int disassembleInstruction(Chunk *chunk, int offset)
{
	printf("%04d ", offset);
	int lineNumber = *(const int *)list_get(chunk->lines, offset);
	int previousLineNumber = offset > 0 ? *(const int *)list_get(chunk->lines, offset - 1) : -1;
	if (offset > 0 && lineNumber == previousLineNumber) {
		printf("   | ");
	} else {
		printf("%4d ", lineNumber);
	}

	uint8_t instruction = *(const uint8_t *)list_get(chunk->opcodes, offset);
	switch (instruction)
	{
	case OP_CONSTANT:
		return constantInstruction("OP_CONSTANT", chunk, offset);
	case OP_ADD:
		return simpleInstruction("OP_ADD", offset);
	case OP_SUBTRACT:
		return simpleInstruction("OP_SUBTRACT", offset);
	case OP_MULTIPLY:
		return simpleInstruction("OP_MULTIPLY", offset);
	case OP_DIVIDE:
		return simpleInstruction("OP_DIVIDE", offset);
	case OP_NEGATE:
		return simpleInstruction("OP_NEGATE", offset);
	case OP_RETURN:
		return simpleInstruction("OP_RETURN", offset);
	default:
		printf("Unknown opcode %d\n", instruction);
		return offset + 1;
	}
}
