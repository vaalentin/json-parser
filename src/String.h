#ifndef H_STRING
#define H_STRING

typedef struct String {
	int *array;
	size_t size;
	size_t used;
} String;

void initString(String *string, size_t size);

void appendString(String *string, char character);

void emptyString(String *string);

void clearString(String *string);

void printString(String *string);

#endif