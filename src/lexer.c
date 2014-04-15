#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Token.h"
#include "Tokenlist.h"
#include "Buffer.h"

void processToken(Tokenlist *list, char type[], char value[]) {
	
	Token token;
	// pointers to NULL (avoid segmentation fault)
	token.type = NULL;
	token.value = NULL;

	token.type = type;
	
	if(value != NULL) {
		// malloc the value pointer
		token.value = malloc(strlen(value) + 1);
		// copy value
		strcpy(token.value, value);
	}
	
	insertTokenlist(list, token);
}

void lex(char path[]) {

	FILE* file = NULL;
	file = fopen(path, "r");

	if(file != NULL) {

		char character;
		int line = 0, column = 0, start = 0, end = 0;
		bool buffering = false;

		Tokenlist tokens;
		initTokenlist(&tokens);

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
						processToken(&tokens, "LEFT_BRACKET", NULL);
						break;
					}

				case '}':
					if(!buffering) {
						processToken(&tokens, "RIGHT_BRACKET", NULL);
						break;
					}

				case '[':
					if(!buffering) {
						processToken(&tokens, "LEFT_SQUARE", NULL);
						break;
					}

				case ']':
					if(!buffering) {
						processToken(&tokens, "RIGHT_SQUARE", NULL);
						break;
					}

				case ':':
					if(!buffering) {
						processToken(&tokens, "ASSIGNATION", NULL);
						break;
					}

				case ',':
					if(!buffering) {
						processToken(&tokens, "COMA", NULL);
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

						processToken(&tokens, "VALUE", value);
						emptyBuffer(&buffer);

					} else {

						start = column + 1;
						
					}
					processToken(&tokens, "QUOTE", NULL);
					break;

				default:
					if(buffering) {
						insertBuffer(&buffer, character);
					}
					break;
			}

			column++;

		} while(character != EOF);

		dumpTokenlist(&tokens);

	} else {
		printf("File not found\n");
	}

}