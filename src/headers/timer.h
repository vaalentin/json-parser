#include <sys/time.h>
#include <math.h>

#ifndef H_TIMER
#define H_TIMER

/**
 * Compute the difference between two timeval
 *
 * @param result pointer to a timeval struct
 * @param start pointer to a timeval struct
 * @param end pointer to a timeval struct
 */
void elapsedTime(struct timeval *result, struct timeval *start, struct timeval *end);

/**
 * Print the timeval (in ms)
 *
 * @param time pointer to a timeval struct
 */
void printTime(struct timeval *time);

#endif