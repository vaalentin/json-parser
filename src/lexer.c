#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"
#include "Buffer.h"

void lex(char path[]) {
	printf("reading %s\n", path);

	FILE* file = NULL;
	file = fopen(path, "r");

	int currentChar = 0;
	if(file != NULL) {

		printf("File found \n");

		int currentLine = 0, currentCol = 0;
		int start = 0; // to tempor
		
		// our buffer
		Buffer buffer;
		initBuffer(&buffer, 1);

		bool quotationOpen = false;

		// loop through each characters
		do {

			currentChar = fgetc(file);

			// match the current character
			if(currentChar == '\n') {
				currentLine++;
				currentCol = 0;
			}
			else if(currentChar == '{') {
				printf("%d %d | ", currentLine, currentCol);
				printf("LEFT_BRACKET\n");
			}
			else if(currentChar == '}') {
				printf("%d %d | ", currentLine, currentCol);
				printf("RIGHT_BRACKET\n");
			}
			else if(currentChar == '"') {
				// switch quotationOpen
				// start the buffering
				quotationOpen = !quotationOpen;
				// if we just found a closing "
				// get the buffer value and reset it
				if(!quotationOpen) {
					printf("%d %d-%d | '", currentLine, start, currentCol - 1);
					
					// get the buffer value
					char text[buffer.used + 1];
					for(int i = 0; i < buffer.used; i++) {
						//printf("%c", buffer.array[i]);
						text[i] = buffer.array[i];
						text[i + 1] = '\0';
					}

					printf("%s", text);

					// empty the buffer
					emptyBuffer(&buffer);

					printf("'\n");
				} else {
					start = currentCol + 1;
				}
				printf("%d %d | ", currentLine, currentCol);
				printf("QUOTE\n");
			}
			else if(currentChar == '[') {
				printf("%d %d | ", currentLine, currentCol);
				printf("LEFT_SQUARE\n");
			}
			else if(currentChar == ']') {
				printf("%d %d | ", currentLine, currentCol);
				printf("RIGHT_SQUARE\n");
			}
			else if(currentChar == ':') {
				printf("%d %d | ", currentLine, currentCol);
				printf("ASSIGNATION\n");
			}
			else if(currentChar == ',') {
				printf("%d %d | ", currentLine, currentCol);
				printf("COMMA\n");
			}
			else {
				// append the current character to the buffer
				if(quotationOpen) {
					appendBuffer(&buffer, currentChar);
				}
			}

			currentCol++;
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}