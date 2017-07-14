//============================================================================
// Name        : ArrayLeftRotation.cpp
// https://www.hackerrank.com/challenges/array-left-rotation
//
//============================================================================
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	long int arrSize, numLRotations;
	cin >> arrSize >> numLRotations;
	vector <long int> arr;
	arr.resize(arrSize);
	for (long int i=0; i<arrSize; i++) {
		cin >> arr[i];
	}
	rotate(arr.begin(),arr.begin()+numLRotations,arr.end());
	for (long int k=0; k<arrSize; k++) {
		printf("%li ",arr[k]);
	}
	printf ("\n");
    return 0;
}
