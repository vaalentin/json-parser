/**
 * \file main.c
 * \version 0.0.1
 */
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(int argc, char *argv[]) {
	lex("example.json");
	return 0;
}