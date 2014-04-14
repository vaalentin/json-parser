#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"

void initBuffer(Buffer *buffer, size_t size) {
	buffer->array = (int *)malloc(size * sizeof(char));
	buffer->size = size;
	buffer->used = 0;
}

void appendBuffer(Buffer *buffer, char character) {
	if(buffer->used == buffer->size) {
		buffer->size *= 2;
		buffer->array = (int *)realloc(buffer->array, buffer->size * sizeof(char));
	}
	buffer->array[buffer->used++] = character;
}

void emptyBuffer(Buffer *buffer) {
	buffer->array[0] = '\0';
	buffer->used = 0;
	buffer->size = 0;
}

void clearBuffer(Buffer *buffer) {
	free(buffer->array);
	buffer->array = NULL;
	buffer->used = 0;
	buffer->size = 0;
}

void printBuffer(Buffer *buffer) {
	for(int i = 0; i < buffer->used; i++) {
		printf("%c", buffer->array[i]);
	}
}