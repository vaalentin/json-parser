#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"

void initBuffer(Buffer *buffer) {
	buffer->used = 0;
	buffer->size = 1;
	buffer->elements = (char *)malloc(1 * sizeof(char));
}

void insertBuffer(Buffer *buffer, char character) {
	if(buffer->used == buffer->size) {
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