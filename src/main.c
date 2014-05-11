#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "lexer.h"
#include "Token.h"
#include "Tokenlist.h"
#include "parser.h"
#include "colors.h"
#include "timer.h"

int main(int argc, char *argv[]) {

	struct timeval timeStart;
	gettimeofday(&timeStart, NULL);

	Tokenlist tokens;
	tokens = lex("example.json");
	printf("%s%s%s\n", GREEN, "Lexing finished", COLOR_RESET);

	struct timeval timeEnd;
	gettimeofday(&timeEnd, NULL);

	struct timeval timeElapsed;
	elapsedTime(&timeElapsed, &timeStart, &timeEnd);

	printf("%sLexing finished in: ", BLUE);
	printTime(&timeElapsed);
	printf("%s\n", COLOR_RESET);

	return 0;

}