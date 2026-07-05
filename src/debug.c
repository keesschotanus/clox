#include <stdio.h>

#include <collections/list/list.h>

#include "debug.h"


static int offset = 0;
static void disassembleInstruction(const void * data)
{
	printf("%04d ", offset++);

  	uint8_t instruction = *(const uint8_t *)data;
  	switch (instruction) {
    	case OP_RETURN:
		printf("%s\n", "OP_RETURN");
		break;
    	default:
      		printf("Unknown opcode %d\n", instruction);
      
	}
}

void disassembleChunk(list_t chunk, const char* name) {
  printf("== %s ==\n", name);

  list_visit(chunk, &disassembleInstruction);
}