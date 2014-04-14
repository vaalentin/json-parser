/**
 * \file Buffer.c
 * \brief Buffer implementation
 * \version 0.0.1
 */
#include <stdio.h>
#include <stdlib.h>
#include "Buffer.h"

void initBuffer(Buffer *buffer, size_t size) {
	// by using malloc, we will be able to use realloc
	buffer->array = (int *)malloc(size * sizeof(char));
	buffer->size = size;
	buffer->used = 0;
}

void appendBuffer(Buffer *buffer, char character) {
	// if we reach the max size, * 2
	if(buffer->used == buffer->size) {
		buffer->size *= 2;
		buffer->array = (int *)realloc(buffer->array, buffer->size * sizeof(char));
	}
	buffer->array[buffer->used++] = character;
}

void emptyBuffer(Buffer *buffer) {
	// '\0' close the array
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