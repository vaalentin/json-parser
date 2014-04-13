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

		char buffer[100] = "";
		bool quotationOpen = false;

		// lop through each characters
		do {

			currentChar = fgetc(file);

			// match the current character
			if(currentChar == '{') {
				printf("LEFT_BRACKET\n");
			}
			else if(currentChar == '}') {
				printf("RIGHT_BRACKET\n");
			}
			else if(currentChar == '"') {
				// switch quotationOpen
				// start the buffering
				quotationOpen = !quotationOpen;
				// if we just found a closing "
				// get the buffer value and reset it
				if(!quotationOpen) {
					printf("%s\n", buffer);
					buffer[0] = '\0';
				}
			}
			else if(currentChar == '[') {
				printf("LEFT_SQUARE\n");
			}
			else if(currentChar == ']') {
				printf("RIGHT_SQUARE\n");
			}
			else if(currentChar == ':') {
				printf("ASSIGNATION\n");
			}
			else if(currentChar == ',') {
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
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}