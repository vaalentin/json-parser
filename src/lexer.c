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
#include "Tokenlist.h"
#include "Token.h"

void processToken(Tokenlist *list, char type[]) {
	Token tok;
	tok.type = type;

	appendTokenlist(list, tok);
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

		// our tokenlist (object returned)
		Tokenlist tokens;
		initTokenlist(&tokens, 100);
		
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
					processToken(&tokens, "LEFT_BRACKET");
					printToken("LEFT_BRACKET", NULL, currentLine, currentCol, currentCol);
					break;

				case '}':
					processToken(&tokens, "RIGHT_BRACKET");
					printToken("RIGHT_BRACKET", NULL, currentLine, currentCol, currentCol);
					break;

				case '[':
					processToken(&tokens, "LEFT_SQUARE");
					printToken("LEFT_SQUARE", NULL, currentLine, currentCol, currentCol);
					break;

				case ']':
					processToken(&tokens, "RIGHT_SQUARE");
					printToken("RIGHT_SQUARE", NULL, currentLine, currentCol, currentCol);
					break;

				case ':':
					processToken(&tokens, "ASSIGNATION");
					printToken("ASSIGNATION", NULL, currentLine, currentCol, currentCol);
					break;

				case ',':
					processToken(&tokens, "COMA");
					printToken("COMA", NULL, currentLine, currentCol, currentCol);
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
						processToken(&tokens, "VALUE");
						printToken("VALUE", text, currentLine, start, currentCol);
					} else {
						start = currentCol + 1; // otherwise, a word to capture started
					}
					processToken(&tokens, "QUOTE");
					printToken("QUOTE", NULL, currentLine, currentCol, currentCol);
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

		// dump the Tokenlist
		int size = getTokenlistSize(&tokens);
		printf("\n%d TOKENS FOUND\n", size);

	} else {
		printf("File not found \n");
	}

}