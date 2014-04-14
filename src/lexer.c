/**
 * \file lexer.c
 * \brief lexer implementation
 * \version 0.0.1
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"
#include "Buffer.h"


void appendToken(char type[], char value[], int line, int start, int end) {
	if(value != NULL) {
		printf("%d | %d-%d | %s => %s\n", line, start, end, type, value);
	} else {
		printf("%d | %d-%d | %s\n", line, start, end, type);
	}
}

void lex(char path[]) {

	printf("reading %s\n", path);

	FILE* file = NULL;
	file = fopen(path, "r");

	if(file != NULL) {

		/**
		 * During the loop
		 * currentChar holds the current character
		 * currentLine holds the current line number
		 * currentCol holds the current column number
		 * start tmp value to hold the start of a catcheable sequence
		 */
		int currentChar = 0, currentLine = 0, currentCol = 0, start = 0;
		bool quotationOpen = false;
		
		// our buffer
		Buffer buffer;
		initBuffer(&buffer, 1);

		// loop through each characters
		do {

			currentChar = fgetc(file);

			/**
			 * match the current character
			 * 
			 * Json reserved characters : { } [ ] " , :
			 * but only outside of " "
			 * that's why we use quotationOpen as a switch to know if we should capture them
			 */
			if(currentChar == '\n') {
				currentLine++;
				currentCol = 0;
			}
			else if(currentChar == '{') {
				appendToken("LEFT_BRACKET", NULL, currentLine, currentCol, currentCol);
			}
			else if(currentChar == '}') {
				appendToken("RIGHT_BRACKET", NULL, currentLine, currentCol, currentCol);
			}
			else if(currentChar == '[') {
				appendToken("LEFT_SQUARE", NULL, currentLine, currentCol, currentCol);
			}
			else if(currentChar == ']') {
				appendToken("RIGHT_SQUARE", NULL, currentLine, currentCol, currentCol);
			}
			else if(currentChar == '"') {
				// start the buffering
				quotationOpen = !quotationOpen;
				// we just found a closing "
				if(!quotationOpen) {

					// capture the buffer content
					// add 1 to have enough space to put '\0'
					char text[buffer.used + 1];
					for(int i = 0; i < buffer.used; i++) {
						text[i] = buffer.array[i];
						text[i + 1] = '\0';
					}

					appendToken("VALUE", text, currentLine, start, currentCol);

					// empty the buffer
					emptyBuffer(&buffer);

				} else {
					// otherwise, a word to capture started
					start = currentCol + 1;
				}

				appendToken("QUOTE", NULL, currentLine, currentCol, currentCol);
			}
			else if(currentChar == ':') {
				appendToken("ASSIGNATION", NULL, currentLine, currentCol, currentCol);
			}
			else if(currentChar == ',') {
				appendToken("COMA", NULL, currentLine, currentCol, currentCol);
			}
			else {
				// not a reserved character, append it to the buffer
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