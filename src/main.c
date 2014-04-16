#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "Token.h"
#include "Tokenlist.h"
#include "parser.h"

int main(int argc, char *argv[]) {

	Tokenlist tokens;
	tokens = lex("example.json");

	parse(&tokens);

	return 0;
}