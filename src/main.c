#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "Array.h"

int main(int argc, char *argv[]) {
	Array ages;
	initArray(&ages, 5);
	appendArray(&ages, 2);
	printArray(&ages);

	//lex("example.json");
	return 0;
}