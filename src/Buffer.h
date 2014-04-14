/**
 * \file Buffer.h
 * \brief Buffer header
 * \version 0.0.1
 */
#ifndef H_BUFFER
#define H_BUFFER

/**
 * \struct Buffer
 * \brief Buffer structure
 */
typedef struct Buffer {
	int *array;
	size_t size;
	size_t used;
} Buffer;

/**
 * \brief Initialize a buffer
 *
 * \param Buffer *buffer
 * \param size_t size
 */
void initBuffer(Buffer *buffer, size_t size);

/**
 * \brief Append a character to a buffer
 *
 * \param Buffer *buffer
 * \param char character
 */
void appendBuffer(Buffer *buffer, char character);

/**
 * \brief Empty a buffer
 *
 * \param Buffer *buffer
 */
void emptyBuffer(Buffer *buffer);

/**
 * \brief Clear a buffer from the memory
 *
 * \param Buffer *buffer
 */
void clearBuffer(Buffer *buffer);

/**
 * \brief Output the content of a buffer
 *
 * \param Buffer *buffer
 */
void printBuffer(Buffer *buffer);

#endif