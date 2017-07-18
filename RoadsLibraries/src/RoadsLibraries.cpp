//============================================================================
// Name        : RoadsLibraries.cpp
// https://www.hackerrank.com/challenges/torque-and-development
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
 	int q;
 	int nCities, mRoads;
 	long int libCost, roadCost;
 	long int totalCost;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        cin >> nCities >> mRoads >> libCost >> roadCost;
         if (mRoads == 0) {
        	totalCost = nCities * libCost;
      	   printf ("%li\n", totalCost);
      	   return 0;
        }
        if (nCities == 0) {
        	totalCost = 0;
      	   printf ("%li\n", totalCost);
      	   return 0;
        }
        if (libCost <= roadCost){
    	   totalCost = nCities * libCost;
    	   printf ("%li\n", totalCost);
    	   return 0;
        }

        vector< vector<int> > cityRoad(2,vector<int>(mRoads+1));
        for(int i = 0; i < mRoads; i++){
            cin >> cityRoad[0][i] >> cityRoad[1][i];
        }

        for(int i = 0; i < mRoads; i++){
            cout<< cityRoad[0][i] << " " << cityRoad[1][i] << endl;;
        }

// Find city pairs & connections
        vector< vector<int> > roadCities(mRoads+2,vector<int>(mRoads+2));

        for (int j2=0; j2<mRoads; j2++){
           	roadCities[cityRoad[0][j2]-1][cityRoad[1][j2]-1] = 1;
           	roadCities[cityRoad[1][j2]-1][cityRoad[0][j2]-1] = 1;

        }
            for (int i1=0; i1<mRoads; i1++) {
        		roadCities[i1][i1] = 1;
        	}
// FInd gaps where there are no connecting roads
        	int roadGap = 0;
        	for (int i2=0; i2<mRoads-1; i2++) {
        		if  ((!roadCities[i2][i2+1]) && (!roadCities[i2+1][i2])) {
        			roadGap++;
        		}
        	}
        	totalCost = (roadGap + 1) * libCost + (mRoads - (roadGap + 1)) * roadCost;
      	    printf ("%li\n", totalCost);
        }

    return 0;
}

