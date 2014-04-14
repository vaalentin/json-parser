#ifndef H_BUFFER
#define H_BUFFER

typedef struct Buffer {
	int *array;
	size_t size;
	size_t used;
} Buffer;

void initBuffer(Buffer *buffer, size_t size);

void appendBuffer(Buffer *buffer, char character);

void emptyBuffer(Buffer *buffer);

void clearBuffer(Buffer *buffer);

void printBuffer(Buffer *buffer);

#endif