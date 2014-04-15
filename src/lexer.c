#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Token.h"
#include "Tokenlist.h"
#include "Buffer.h"

void processToken(Tokenlist *list, char type[]) {
	printf("token type %s found\n", type);
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
						processToken(&tokens, "LEFT_BRACKET");
						break;
					}

				case '}':
					if(!buffering) {
						processToken(&tokens, "RIGHT_BRACKET");
						break;
					}

				case '[':
					if(!buffering) {
						processToken(&tokens, "LEFT_SQUARE");
						break;
					}

				case ']':
					if(!buffering) {
						processToken(&tokens, "RIGHT_SQUARE");
						break;
					}

				case ':':
					if(!buffering) {
						processToken(&tokens, "ASSIGNATION");
						break;
					}

				case ',':
					if(!buffering) {
						processToken(&tokens, "COMA");
						break;
					}

				case '"':
					buffering = !buffering;
					if(!buffering) {

						dumpBuffer(&buffer);
						emptyBuffer(&buffer);

					} else {

						start = column + 1;
						
					}
					processToken(&tokens, "QUOTE");
					break;

				default:
					if(buffering) {
						insertBuffer(&buffer, character);
					}
					break;
			}

			column++;

		} while(character != EOF);

	} else {
		printf("File not found\n");
	}

}