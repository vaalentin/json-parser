#include <sys/time.h>
#include <math.h>

#ifndef H_TIMER
#define H_TIMER

int elapsedTime(struct timeval *result, struct timeval *start, struct timeval *end);

void printTime(struct timeval *time);

#endif