#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "Tokenlist.h"

int main(int argc, char *argv[]) {

	Tokenlist tokens;
	tokens = lex("example.json");
	dumpTokenlist(&tokens);

	return 0;
}