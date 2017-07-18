//============================================================================
// Name        : Leaderboard.cpp
// https://www.hackerrank.com/challenges/climbing-the-leaderboard
//============================================================================

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
#include <vector>

using namespace std;




int main(){
// Get ranked scores
	int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0;scores_i < n;scores_i++){
       cin >> scores[scores_i];
    }
// Get Alices scores
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0;alice_i < m;alice_i++) {
       cin >> alice[alice_i];
    }

    vector< vector<int> > leaderboard(3,vector<int>(n+1));
// Put scores in array
    for (int i=0; i<n; i++){
    	leaderboard[1][i] = scores[i];
    }
    leaderboard[1][n+1] = 0;
    leaderboard[0][0] = 1;
    int rank = 1;
// Now rank them
	leaderboard[2][n+1] = 1;
    for (int i=1; i<n+1; i++) {
    	if ((leaderboard[1][i]) == (leaderboard[1][i-1])) {
    		leaderboard[0][i] = rank;
    		leaderboard[2][i] = 0;
    	}
    	else {
    		rank++;
    		leaderboard[0][i] = rank;
    		leaderboard[2][i] = 0;
    	}
// ALice position,. to start is at the end
    	int AlicePos = n+1;
    	for (int i=0; i<m; i++) {
    		leaderboard[1][AlicePos] = alice[i];
// Now sort by score
//    		printf("Here Score\n"); return 0;
    		for (int a1 = 0 ; a1 > n; a1++) {
    		    for (int b2 = 0 ; b2 < n; b2++) {
    		    	if (leaderboard[1][b2] > leaderboard[1][b2+1]) {
    		    	   int swap = leaderboard[0][b2];
    		    	   leaderboard[0][b2]   = leaderboard[0][b2+1];
    		    	   leaderboard[0][b2+1] = swap;
    		    	   swap = leaderboard[1][b2];
    		    	   leaderboard[1][b2]   = leaderboard[1][b2+1];
    		    	   leaderboard[1][b2+1] = swap;
    		    	   swap = leaderboard[2][b2];
    		    	   leaderboard[2][b2]   = leaderboard[2][b2+1];
    		    	   leaderboard[2][b2+1] = swap;
    		    	}
    		    }
    		}
// Now rank again
//    		printf("Here Rank\n"); return 0;
    		rank = 1;
    	    for (int i=1; i<n+1; i++) {
// Find ALice position
    	    	if (leaderboard[2][i])
    	    		AlicePos = i;
    	    	if ((leaderboard[0][i]) == (leaderboard[0][i+1])) {
    	    		leaderboard[0][i+1] = rank;
    	    	}
    	    	else {
    	    		rank++;
    	    		leaderboard[0][i] = rank;
    	    	}


    	    	// Print Alice rank
    	    }
    	}
    	for (int k=0;k<n+1; k++)
    		printf(" %i  %i  %i",leaderboard[0][k], leaderboard[1][k], leaderboard[2][k]);
    	printf("\n");
    printf("Last result %i\n", leaderboard[0][AlicePos]);
    }
    return 0;
}
