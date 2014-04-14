#ifndef H_TOKENLIST
#define H_TOKENLIST

typedef struct Tokenlist {
	int *array;
	size_t size;
	size_t used;
} Tokenlist;

void initTokenlist(Tokenlist *list, size_t size);

void appendTokenlist(Tokenlist *list, int element);

void emptyTokenlist(Tokenlist *list);

void clearTokenlist(Tokenlist *list);

void printTokenlist(Tokenlist *array);

#endif