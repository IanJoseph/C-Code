// Original code and problem statement: https://www.hackerrank.com/challenges/2d-array
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
// My code starts here
    int hourglassMax = -9999, hourglassTotal;
    vector< vector<int> > myHourglass(3,vector<int>(3));
    for (int i=0; i<4; i++){
    	for (int j=0; j<4; j++){
    		hourglassTotal = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
			if (hourglassTotal > hourglassMax)
				hourglassMax = hourglassTotal;
    	}
    }

	cout << hourglassMax << endl;
// My code ends here
    return 0;
}
