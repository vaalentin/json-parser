#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

// TEST

#include "Buffer.h"
#include "Token.h"
#include "Tokenlist.h"

// END TEST

int main(int argc, char *argv[]) {

	// TEST

	// buffer
	Buffer buffer;
	initBuffer(&buffer);
	insertBuffer(&buffer, 'h');
	insertBuffer(&buffer, 'e');
	insertBuffer(&buffer, 'l');
	insertBuffer(&buffer, 'l');
	insertBuffer(&buffer, 'o');
	insertBuffer(&buffer, ' ');
	insertBuffer(&buffer, 'w');
	insertBuffer(&buffer, 'o');	
	insertBuffer(&buffer, 'r');
	insertBuffer(&buffer, 'l');
	insertBuffer(&buffer, 'd');
	dumpBuffer(&buffer);
	emptyBuffer(&buffer);
	insertBuffer(&buffer, 'w');
	insertBuffer(&buffer, 'o');
	insertBuffer(&buffer, 'w');
	dumpBuffer(&buffer);

	// Tokenlist and Token
	Tokenlist list;
	initTokenlist(&list);
	for(int i = 0; i < 9; i++) {
		Token token;
		token.type = "TEST";
		token.line = i;
		token.start = i * 2;
		token.end = i * 3;

		insertTokenlist(&list, token);
	}
	dumpTokenlist(&list);

	// END TEST

	return 0;
}