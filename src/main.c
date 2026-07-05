#include <collections/list/list.h>
#include <stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(void)
{
	puts("Running clox...");
	list_t chunks = list_create(100, sizeof(uint8_t));
	int8_t byte = OP_RETURN;
	list_append(chunks, &byte);

	disassembleChunk(chunks, "test chunk");
	list_free(chunks);
	return 0;
}