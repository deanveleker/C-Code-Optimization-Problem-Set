#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int oddball(int *arr, int len);
int randGenerator(int *arr, int len);

#ifndef N
	#define N (40)
#endif

#define ARRLEN (2*(N) - 1)

static double TimeSpecToSeconds(struct timespec* ts)
{
    return (double)ts->tv_sec + (double)ts->tv_nsec / 1000000000.0;
}

int main()
{
	/* Keep this line here */
	srand(time(NULL));
    
    struct timespec start;
    struct timespec end;
    double elapsedSeconds;
    
	int *arr = malloc(ARRLEN*sizeof(int));
	int num;

	if (!arr) {
		return -1;
	}
    
    clock_gettime(CLOCK_MONOTONIC, &start);
	randGenerator(arr, ARRLEN);
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	elapsedSeconds = TimeSpecToSeconds(&end) - TimeSpecToSeconds(&start);
    printf("Random generator time: %f seconds\n", elapsedSeconds);
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	num = oddball(arr, ARRLEN);
	clock_gettime(CLOCK_MONOTONIC, &end);
    
	printf("Oddball is %d\n", num);
	
	elapsedSeconds = TimeSpecToSeconds(&end) - TimeSpecToSeconds(&start);
    printf("Oddball execution time: %f seconds\n", elapsedSeconds);
    
    free(arr);
    
	return 0;
}

