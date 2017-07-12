#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int migratoryBirds(int ar_size, int* ar) {
	int birdType[6]= {0, 0, 0, 0, 0, 0};
	for (int i=0; i<ar_size; i++) {
		switch (ar[i]) {
			case 1: birdType[1]++;
				break;
			case 2: birdType[2]++;
				break;
			case 3: birdType[3]++;
				break;
			case 4: birdType[4]++;
				break;
			case 5: birdType[5]++;
				break;
		}
	}
	int mostCommon = 0, highBirds = 0;
	for (int i = 1; i<6; i++)
		if (birdType[i]>highBirds) {
			highBirds = birdType[i];
			mostCommon = i;
		}
	return mostCommon;
}

int main() {
    int n;
    scanf("%i", &n);
    int *ar = (int*) malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    int result = migratoryBirds(n, ar);
    printf("%d\n", result);
    return 0;
}
