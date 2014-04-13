#include <stdio.h>
#include <stdlib.h>

void lex(char path[]) {
	printf("reading %s\n", path);

	FILE* file = NULL;
	file = fopen(path, "r");

	int currentChar = 0;
	if(file != NULL) {

		printf("File found \n");

		do {
			
			currentChar = fgetc(file);
			printf("%c\n", currentChar);
			
		} while (currentChar != EOF);

		fclose(file);

	} else {
		printf("File not found \n");
	}

}