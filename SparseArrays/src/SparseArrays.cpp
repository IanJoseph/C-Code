//============================================================================
// Name        : SparseArrays.cpp
// https://www.hackerrank.com/challenges/sparse-arrays
//============================================================================

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int numStrings, numQueries;
	cin >> numStrings;
	vector <string> list, query;
	vector <int> occurs;
	list.resize(numStrings);
	for (int i=0; i<numStrings; i++)
		cin >> list[i];
	cin >> numQueries;
	query.resize(numQueries);
	occurs.resize(numQueries);
	for (int i=0; i<numQueries; i++)
			cin >> query[i];

	for (int i=0; i<numQueries; i++) {
		occurs[i]=0;
		for (int j=0; j<numStrings; j++)
			if (query[i].compare(list[j]) == 0)
				occurs[i]++;
	}
	for (int i=0; i<numQueries; i++)
		cout << occurs[i] << endl;

	return 0;
}




