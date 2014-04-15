#ifndef H_BUFFER
#define H_BUFFER

/**
 * Buffer is a char array to which we can dynamically add new char
 *
 * @struct Buffer
 */
typedef struct Buffer {
	char *elements;
	int used, size;
} Buffer;

/**
 * Initialize a buffer at length 0
 * by calling malloc on the elements pointer
 *
 * @fn initBuffer
 * @param buffer pointer to a Buffer
 */
void initBuffer(Buffer *buffer);

/**
 * Insert a new element at the end of the chunck of memory pointed by elements
 * realloc the chunck of memory if the element we're trying to insert is overflow
 *
 * @fn insertBuffer
 * @param buffer pointer to a Buffer
 * @param character char
 */
void insertBuffer(Buffer *buffer, char character);

/**
 * Put the buffer back to his initial state
 *
 * @fn emptyBuffer
 * @param buffer pointer to a Buffer
 */
void emptyBuffer(Buffer *buffer);

/**
 * Dump the content of the buffer with printf
 *
 * @fn dumpBuffer
 * @param buffer pointer to a Buffer
 */
void dumpBuffer(Buffer *buffer);

#endif