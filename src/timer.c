#include <stdio.h>
#include <sys/time.h>
#include <math.h>

void elapsedTime(struct timeval *result, struct timeval *start, struct timeval *end) {
	long int difference = (end->tv_usec + 1000000 * end->tv_sec) - (start->tv_usec + 1000000 * start->tv_sec);
	result->tv_sec = difference / 1000000;
	result->tv_sec = difference % 1000000;
}

void printTime(struct timeval *time) {
	char buffer[30];
	time_t currentTime;
	printf("%ld.%06dms\n", time->tv_sec, time->tv_usec);
}