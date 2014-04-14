#include <stdio.h>
#include <stdlib.h>
#include "String.h"

void initString(String *string, size_t size) {
	string->array = (int *)malloc(size * sizeof(char));
	string->size = size;
	string->used = 0;
}

void appendString(String *string, char character) {
	if(string->used == string->size) {
		string->size *= 2;
		string->array = (int *)realloc(string->array, string->size * sizeof(char));
	}
	string->array[string->used++] = character;
}

void emptyString(String *string) {
	string->array[0] = '\0';
	string->used = 0;
	string->size = 1;
}

void printString(String *string) {
	for(int i = 0; i < string->used; i++) {
		printf("%c\n", string->array[i]);
	}
}