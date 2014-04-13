#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void lex(char path[]) {
	printf("reading %s\n", path);

	FILE* file = NULL;
	file = fopen(path, "r");

	int currentChar = 0;
	if(file != NULL) {

		printf("File found \n");

		do {

			currentChar = fgetc(file);

			char buffer[] = "";

			switch(currentChar) {
				case '{':
					printf(" LEFT_BRACKET ");
					break;

				case '}':
					printf(" RIGHT_BRACKET ");
					break;

				case '"':
					printf(" QUOTATION ");
					break;

				case '[':
					printf(" LEFT_SQUARE ");
					break;

				case ']':
					printf(" RIGHT_SQUARE ");
					break;

				case ':':
					printf(" EQUALS ");
					break;

				case ',':
					printf(" COMMA ");
					break;

				default:
					printf("%c", currentChar);
					break;
			}
			
			//printf("%c\n", currentChar);
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}