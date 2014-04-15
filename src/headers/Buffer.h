#ifndef H_BUFFER
#define H_BUFFER

typedef struct Buffer {
	char *elements;
	int used, size;
} Buffer;

void initBuffer(Buffer *buffer);

void insertBuffer(Buffer *buffer, char character);

void emptyBuffer(Buffer *buffer);

void dumpBuffer(Buffer *buffer);

#endif