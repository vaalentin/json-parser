#include <stdio.h>
#include "Token.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void printToken(char type[], char value[], int line, int start, int end) {
	if(value != NULL) {
		printf("%d | " ANSI_COLOR_MAGENTA "%d-%d" ANSI_COLOR_RESET " | " ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET " => " ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, line, start, end, type, value);
	} else {
		printf("%d | " ANSI_COLOR_MAGENTA "%d-%d" ANSI_COLOR_RESET " | " ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, line, start, end, type);
	}
}