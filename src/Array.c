#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void initArray(Array *array, size_t size) {
	array->array = (int *)malloc(size * sizeof(int));
	array->size = size;
	array->used = 0;
}

void appendArray(Array *array, int element) {

}

void clearArray(Array *array) {

}

void printArray(Array *array) {
	for(int i = 0; i < array->size; i++) {
		printf("%d\n", array->array[i]);
	}
}