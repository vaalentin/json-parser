#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Token.h"
#include "Tokenlist.h"
#include "Buffer.h"
#include "colors.h"

void processToken(Tokenlist *list, char type[], char value[], int line, int start, int end) {
	Token token;
	// pointers to NULL
	// (to avoid segmentation faults)
	token.type = NULL;
	token.value = NULL;

	// assign the values
	token.line = line;
	token.start = start;
	token.end = end;

	token.type = type;
	if(value != NULL) {
		// assign the correct ammount of memory to the element pointer
		// which is the size of value + 1
		// then we copy value
		// (+1 because otherwise there isn't enough space for the ending '\0')
		token.value = malloc(strlen(value) + 1);
		strcpy(token.value, value);
	}

	// insert our newly created Token to the Tokenlist
	insertTokenlist(list, token);

	printf("%s%s%s%s\n", "new token ", CYAN, token.type, COLOR_RESET);

}

Tokenlist lex(char path[]) {

	FILE* file = NULL;
	file = fopen(path, "r");

	// tokens will holds the tokens found
	// and then be returned
	Tokenlist tokens;
	initTokenlist(&tokens);

	if(file != NULL) {

		// informations we're gonna need during the loop
		char character;
		int line = 0, column = 0, start = 0, end = 0;
		bool buffering = false, capturingDigit = false;

		// buffer will holds the characters that we want to capture
		// (between " ")
		Buffer buffer;
		initBuffer(&buffer);

		// loop through each characters
		do {

			character = fgetc(file);

			// if we have a space, turn off the digit capturing
			// e.g: 19.29 <= here
			if(capturingDigit && character == ' ') {
				capturingDigit = !capturingDigit;
			}

			switch(character) {
				// new line
				case '\n':
					line++;
					column = 0;
					break;

				case '{':
					// process only if we're not buffering
					// e.g: "hello {world}"
					if(!buffering) {
						processToken(&tokens, "L_BRACKET", NULL, line, column, column);
						break;
					}

				case '}':
					if(!buffering) {
						processToken(&tokens, "R_BRACKET", NULL, line, column, column);
						break;
					}

				case '[':
					if(!buffering) {
						processToken(&tokens, "L_SQUARE", NULL, line, column, column);
						break;
					}

				case ']':
					if(!buffering) {
						processToken(&tokens, "R_SQUARE", NULL, line, column, column);
						break;
					}

				case ':':
					if(!buffering) {
						processToken(&tokens, "ASSIGN", NULL, line, column, column);
						break;
					}

				case ',':
					if(!buffering) {
						processToken(&tokens, "COMA", NULL, line, column, column);
						break;
					}

				case '"':
					// toggle state 
					buffering = !buffering;

					// we just ended the buffering
					if(!buffering) {

						// extract the buffered value
						char value[buffer.used+1];
						for(int i = 0; i < buffer.used; i++) {
							value[i] = buffer.elements[i];
							value[i+1] = '\0';
						}

						processToken(&tokens, "VALUE", value, line, start, column);
						processToken(&tokens, "QUOTE", NULL, line, column, column);

						// reset the buffer
						emptyBuffer(&buffer);

					} else {
						// starting a new buffer
						// keep the current column as the starting point
						start = column + 1;
						
						processToken(&tokens, "QUOTE", NULL, line, column, column);
					}

					break;

				default:
					// still buffering
					if(buffering) {
						insertBuffer(&buffer, character);
					}
					// not buffering, and we have a number
					else if(isdigit(character)) {
						// start buffering and swith captureDigit
						buffering = !buffering;
						capturingDigit = !capturingDigit;
						// capture this character (otherwise it will be skipped)
						insertBuffer(&buffer, character);
					}
					break;
			}

			column++;

		} while(character != EOF);

		return tokens;

	} else {
		printf("%s%s%s\n", RED, "File not found", COLOR_RESET);
	}

	return tokens;

}