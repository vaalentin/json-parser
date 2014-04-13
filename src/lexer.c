#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void append(char text1[], char text2[]) {
	size_t len1 = strlen(text1);
	size_t len2 = strlen(text2);

	char *concat = (char*) malloc(len1 + len2 + 1);

	memcpy(concat, text1, len1);
	memcpy(concat + len1, text2, len2+1);

	strcpy(text1, concat);
}

void lex(char path[]) {
	printf("reading %s\n", path);

	FILE* file = NULL;
	file = fopen(path, "r");

	int currentChar = 0;
	if(file != NULL) {

		printf("File found \n");

		char tmp[] = " ";
		char buffer[] = "";
		bool quotationOpen = false;

		do {

			currentChar = fgetc(file);

			if(currentChar == '{') {
				printf(" LEFT_BRACKET ");
			}
			else if(currentChar == '}') {
				printf(" RIGHT_BRACKET ");
			}
			else if(currentChar == '"') {
				printf(" QUOTATION ");
			}
			else if(currentChar == '[') {
				printf(" LEFT_SQUARE ");
			}
			else if(currentChar == ']') {
				printf(" RIGHT_SQUARE ");
			}
			else if(currentChar == ':') {
				printf(" ASSIGNATION ");
			}
			else if(currentChar == ',') {
				printf(" COMMA ");
			}
			else {
				tmp[0] = currentChar;
				printf("%s", tmp);
			}
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}