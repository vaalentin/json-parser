#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Token.h"
#include "Tokenlist.h"
#include "Buffer.h"

void processToken(Tokenlist *list, char type[], char value[], int line, int start, int end) {
	Token token;
	// pointers to NULL (avoid segmentation fault)
	token.type = NULL;
	token.value = NULL;

	// assign the values
	token.line = line;
	token.start = start;
	token.end = end;

	token.type = type;
	if(value != NULL) {
		// malloc the value pointer
		token.value = malloc(strlen(value) + 1);
		// copy value
		strcpy(token.value, value);
	}
	insertTokenlist(list, token);
}

Tokenlist lex(char path[]) {

	FILE* file = NULL;
	file = fopen(path, "r");

	Tokenlist tokens;
	initTokenlist(&tokens);

	if(file != NULL) {

		char character;
		int line = 0, column = 0, start = 0, end = 0;
		bool buffering = false;

		Buffer buffer;
		initBuffer(&buffer);

		do {

			character = fgetc(file);

			switch(character) {
				case '\n':
					line++;
					column = 0;
					break;

				case '{':
					if(!buffering) {
						processToken(&tokens, "LEFT_BRACKET", NULL, line, column, column);
						break;
					}

				case '}':
					if(!buffering) {
						processToken(&tokens, "RIGHT_BRACKET", NULL, line, column, column);
						break;
					}

				case '[':
					if(!buffering) {
						processToken(&tokens, "LEFT_SQUARE", NULL, line, column, column);
						break;
					}

				case ']':
					if(!buffering) {
						processToken(&tokens, "RIGHT_SQUARE", NULL, line, column, column);
						break;
					}

				case ':':
					if(!buffering) {
						processToken(&tokens, "ASSIGNATION", NULL, line, column, column);
						break;
					}

				case ',':
					if(!buffering) {
						processToken(&tokens, "COMA", NULL, line, column, column);
						break;
					}

				case '"':
					buffering = !buffering;
					if(!buffering) {

						char value[buffer.used+1];
						for(int i = 0; i < buffer.used; i++) {
							value[i] = buffer.elements[i];
							value[i+1] = '\0';
						}

						processToken(&tokens, "VALUE", value, line, start, column);
						emptyBuffer(&buffer);

					} else {

						start = column + 1;
						
					}
					processToken(&tokens, "QUOTE", NULL, line, column, column);
					break;

				default:
					if(buffering) {
						insertBuffer(&buffer, character);
					}
					break;
			}

			column++;

		} while(character != EOF);

		return tokens;

	} else {
		printf("File not found\n");
	}

	return tokens;

}