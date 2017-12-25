#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

/**
 * Function: oddball
 * Description: Baseline implementation for finding the number that
 *   occurs only once in the array.
 * Arguments:
 *   arr - pointer to start of integer array
 *   len - number of elements in array
 * Return:
 *   The number that occurs only once
 */
#ifdef DEFAULT
int oddball(int *arr, int len) {
    int i, j;
    int foundInner;
    int result = 0;
    
    for (i = 0; i < len; i++) {
        foundInner = 0;
        for (j = 0; j < len; j++) {
            if (i == j) {
                continue;
            }
            if (arr[i] == arr[j]) {
                foundInner = 1;
            }
        }
        if (foundInner != 1) {
            result = arr[i];
        }
    }
    
    return result;
}
#endif

#ifdef OPTIMIZE1
int oddball(int *arr, int len) {
    // this algorithm takes advantage of bitwise XOR
    // by XORing every number together, all doubles zero out, leaving the singleton
    //
    // complexity = O(n)
    
    int xord = 0;
    
    for(int i = 0; i < len; i++){
        xord ^= arr[i];
    }
    
    return xord;
}
#endif

#ifdef OPTIMIZE2
int oddball(int *arr, int len) {
    // by taking the sum of all the numbers, and modding it with the absolute
    // value of the difference between that sum and sum(1,n), the result is the
    // number only listed once
    //
    // complexity = O(n)
    
    int upperLimit = (len+1)/2;
    int singletonSum = (upperLimit * (upperLimit + 1)) /2;
    
    int totalSum = 0;
    for(int i = 0; i < len; ++i ){
        totalSum += arr[i];
    }
    
    return totalSum % abs(singletonSum-totalSum);
}
#endif

/**
 * Function: randGenerator
 * Description: Generate a random array that is in compliance with
 *   lab specification
 * Arguments:
 *   arr - pointer to start of integer array
 *   len - number of elements in array
 * Return:
 *   Unused, but feel free to utilize it.
 */
#ifndef RNG
int randGenerator(int *arr, int len) {
    int i, j, r, rcount;
    for (i = 0; i < len; i++) {
        do {
            rcount = 0;
            r = rand()%(len/2 + 1) + 1;
            for (j = 0; j < i && rcount < 2; j++) {
                if (arr[j] == r) {
                    rcount++;
                }
            }
        } while(rcount >= 2);
        arr[i] = r;
    }
    
    return 0;
}

#else
int randGenerator(int *arr, int len) {
    /* Put your code here */
    return 0;
}
#endif


