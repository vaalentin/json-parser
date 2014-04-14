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
#include "Token.h"

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
		 * *currentTag
		 */
		int currentChar = 0, currentLine = 0, currentCol = 0, start = 0;
		bool quotationOpen = false, matched = false;
		char *currentType, *currentValue;
		
		// our buffer
		Buffer buffer;
		initBuffer(&buffer, 1);

		// loop through each characters
		do {

			currentChar = fgetc(file);

			// reset the currentType;
			currentType = "";

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
				currentType = "LEFT_BRACKET";
			}
			else if(currentChar == '}') {
				currentType = "RIGHT_BRACKET";
			}
			else if(currentChar == '[') {
				currentType = "LEFT_SQUARE";
			}
			else if(currentChar == ']') {
				currentType = "RIGHT_SQUARE";
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
					currentType = "EXPRESSION";
					currentValue = text;
					// empty the buffer
					emptyBuffer(&buffer);

				} else {
					// otherwise, a word to capture started
					start = currentCol + 1;
				}

				//printf("%d | %d | ", currentLine, currentCol);
				//printf("QUOTE\n");
			}
			else if(currentChar == ':') {
				currentType = "ASSIGNATION";
			}
			else if(currentChar == ',') {
				currentType = "COMMA";
			}
			else {
				// not a reserved character, append it to the buffer
				if(quotationOpen) {
					appendBuffer(&buffer, currentChar);
				}
			}

			// process the token
			// check if the string pointed by currentType is different than ""
			if(strcmp(currentType, "") != 0) {
				Token token;
				token.type = currentType;
				token.value = currentValue;
				token.line = currentLine;
				token.start = start;
				token.end = currentCol;

				printToken(&token);
			}

			currentCol++;
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}