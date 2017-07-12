/* You are given an array of n integers a0,a1... ,an-1
 * and a positive integer k, .
 * Find and print the number of pairs (i,j) where i<j
 * and ai + aj is divisible by k.
 */


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int divisibleSumPairs(int n, int k, int ar_size, int* ar) {
    int totSumPairs;
	// Complete this function
	return totSumPairs;
}

int main() {
    int n;
    int k;
    scanf("%i %i", &n, &k);
    int *ar = (int *) malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = divisibleSumPairs(n, k, n, ar);
    printf("%d\n", result);
    return 0;
}
