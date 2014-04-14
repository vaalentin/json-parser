#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void initArray(Array *array, size_t size) {
	array->array = (int *)malloc(size * sizeof(int));
	array->size = size;
	array->used = 0;
}

void appendArray(Array *array, int element) {
	if(array->used == array->size) {
		array->size *= 2;
		array->array = (int *)realloc(array->array, array->size * sizeof(int));
	}
	array->array[array->used++] = element;
}

void emptyArray(Array *array) {
	//array->array[0] = '\0';
	array->array = (int *)realloc(array->array, 1 * sizeof(int));
	array->used = 0;
	array->size = 1;
}

void clearArray(Array *array) {
	free(array->array);
	array->array = NULL;
	array->used = 0;
	array->size = 0;
}

void printArray(Array *array) {
	for(int i = 0; i < array->used; i++) {
		printf("%d\n", array->array[i]);
	}
}