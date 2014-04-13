#ifndef H_ARRAY
#define H_ARRAY

typedef struct Array {
	int *array;
	size_t size;
	size_t used;
} Array;

void initArray(Array *array, size_t size);

void appendArray(Array *array, int element);

void clearArray(Array *array);

void printArray(Array *array);

#endif