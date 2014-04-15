#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"

void initBuffer(Buffer *buffer) {
	buffer->used = 0; // keep track of the size of elements
	buffer->size = 1; // the maximum size of elements
	buffer->elements = (char *)malloc(1 * sizeof(char)); // keep the 1 just to be clear
}

void insertBuffer(Buffer *buffer, char character) {
	if(buffer->used == buffer->size) {
		// double the size of the Buffer
		// and realloc the chunck of memory pointed by elements
		buffer->size *= 2;
		buffer->elements = (char *)realloc(buffer->elements, buffer->size * sizeof(char));
	}
	buffer->elements[buffer->used] = character;
	buffer->used++;
}

void emptyBuffer(Buffer *buffer) {
	initBuffer(buffer);
}

void dumpBuffer(Buffer *buffer) {
	printf("Buffer ");
	for(int i = 0; i < buffer->used; i++) {
		printf("%c", buffer->elements[i]);
	}
	printf("\n");
}