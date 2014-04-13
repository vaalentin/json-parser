#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void lex(char path[]) {
	printf("reading %s\n", path);

	FILE* file = NULL;
	file = fopen(path, "r");

	int currentChar = 0;
	if(file != NULL) {

		printf("File found \n");

		int currentLine = 0, currentCol = 0;
		int start = 0; // to tempor
		char buffer[100] = "";
		bool quotationOpen = false;

		// lop through each characters
		do {

			currentChar = fgetc(file);

			// match the current character
			if(currentChar == '\n') {
				currentLine++;
				currentCol = 0;
			}
			else if(currentChar == '{') {
				printf("(line %d) (col %d) | ", currentLine, currentCol);
				printf("LEFT_BRACKET\n");
			}
			else if(currentChar == '}') {
				printf("(line %d) (col %d) | ", currentLine, currentCol);
				printf("RIGHT_BRACKET\n");
			}
			else if(currentChar == '"') {
				// switch quotationOpen
				// start the buffering
				quotationOpen = !quotationOpen;
				// if we just found a closing "
				// get the buffer value and reset it
				if(!quotationOpen) {
					printf("(line %d) (start col %d) (end col %d) | ", currentLine, start, currentCol - 1);
					printf("%s\n", buffer);
					buffer[0] = '\0';
				} else {
					start = currentCol + 1;
				}
				printf("(line %d) (col %d) | ", currentLine, currentCol);
				printf("QUOTE\n");
			}
			else if(currentChar == '[') {
				printf("(line %d) (col %d) | ", currentLine, currentCol);
				printf("LEFT_SQUARE\n");
			}
			else if(currentChar == ']') {
				printf("(line %d) (col %d) | ", currentLine, currentCol);
				printf("RIGHT_SQUARE\n");
			}
			else if(currentChar == ':') {
				printf("(line %d) (col %d) | ", currentLine, currentCol);
				printf("ASSIGNATION\n");
			}
			else if(currentChar == ',') {
				printf("(line %d) (col %d) | ", currentLine, currentCol);
				printf("COMMA\n");
			}
			else {
				// append to the buffer
				if(quotationOpen) {
					size_t length = strlen(buffer);
				    buffer[strlen(buffer)] = currentChar;
				    buffer[length+1] ='\0';
				}
			}

			currentCol++;
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}