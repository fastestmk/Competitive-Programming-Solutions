#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

class RGBStreet{
public:
    int estimateCost(vector<string>);
};

int RGBStreet::estimateCost(vector<string> houses){
    int n = houses.size();
    int DP[25][3];
    int Cost[25][3];

    for(int i = 0; i < n; ++i){
        stringstream Stream(houses[i]); // conversion from string to int
        Stream >> Cost[i][0] >> Cost[i][1] >> Cost[i][2];
    }

    DP[0][0] = Cost[0][0];
    DP[0][1] = Cost[0][1];
    DP[0][2] = Cost[0][2];

    for(int i = 1; i < n; ++i){
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + Cost[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + Cost[i][1];
        DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + Cost[i][2];
    }

    return min(min(DP[n-1][0], DP[n-1][1]), DP[n-1][2]);
}
