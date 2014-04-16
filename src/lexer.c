#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Token.h"
#include "Tokenlist.h"
#include "Buffer.h"

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

			// the main logic is here
			switch(character) {
				// new line
				// increase the line count and reset the column
				case '\n':
					line++;
					column = 0;
					break;

				case '{':
					// process this character only if we're not buffering
					// otherwise we won't be able to catch
					// "hello {world}"
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

					// if we are ending the buffering
					if(!buffering) {

						// extract the buffered value
						char value[buffer.used+1];
						for(int i = 0; i < buffer.used; i++) {
							value[i] = buffer.elements[i];
							value[i+1] = '\0';
						}

						processToken(&tokens, "VALUE", value, line, start, column);

						// reset the buffer
						emptyBuffer(&buffer);

					} else {
						// else, we are starting a new buffering
						// keep the current column as the starting point
						start = column + 1;
					}
					processToken(&tokens, "QUOTE", NULL, line, column, column);
					break;

				default:
					// if a " have been open and not closed yet
					if(buffering) {
						insertBuffer(&buffer, character);
					}
					// else if not buffering yet and we encouter a number
					else if(isdigit(character)) {
						// start buffering and swith captureDigit
						buffering = !buffering;
						capturingDigit = !capturingDigit;
						// capture this (otherwise it will be skipped)
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