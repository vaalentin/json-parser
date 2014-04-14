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

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void appendToken(char type[], char value[], int line, int start, int end) {
	if(value != NULL) {
		printf("%d | " ANSI_COLOR_MAGENTA "%d-%d" ANSI_COLOR_RESET " | " ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET " => " ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, line, start, end, type, value);
	} else {
		printf("%d | " ANSI_COLOR_MAGENTA "%d-%d" ANSI_COLOR_RESET " | " ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, line, start, end, type);
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

			switch(currentChar) {
				case '\n':
					currentLine++;
					currentCol = 0;
					break;
				case '{':
					appendToken("LEFT_BRACKET", NULL, currentLine, currentCol, currentCol);
					break;
				case '}':
					appendToken("RIGHT_BRACKET", NULL, currentLine, currentCol, currentCol);
					break;
				case '[':
					appendToken("LEFT_SQUARE", NULL, currentLine, currentCol, currentCol);
					break;
				case ']':
					appendToken("RIGHT_SQUARE", NULL, currentLine, currentCol, currentCol);
					break;
				case ':':
					appendToken("ASSIGNATION", NULL, currentLine, currentCol, currentCol);
					break;
				case ',':
					appendToken("COMA", NULL, currentLine, currentCol, currentCol);
					break;
				case '"':
					quotationOpen = !quotationOpen; // start the buffering
					if(!quotationOpen) { // finish the buffering
						// capture the buffer content
						char text[buffer.used + 1];
						for(int i = 0; i < buffer.used; i++) {
							text[i] = buffer.array[i];
							text[i + 1] = '\0';
						}
						emptyBuffer(&buffer); // empty the buffer
						appendToken("VALUE", text, currentLine, start, currentCol);
					} else {
						start = currentCol + 1; // otherwise, a word to capture started
					}
					appendToken("QUOTE", NULL, currentLine, currentCol, currentCol);
					break;
				default:
					// not a reserved character, append it to the buffer
					if(quotationOpen) {
						appendBuffer(&buffer, currentChar);
					}
					break;
			}

			currentCol++;
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}