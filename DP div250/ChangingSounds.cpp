#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int start, maxVol;
int dp[55][1005];
vector<int> CI;

int solve(int index, int value){
    if(value > maxVol || value < 0)
        return -1;

    if(index == CI.size())
        return value;

    if(dp[index][value] != -1)
        return dp[index][value];

    int res = -1;
    res = max(res,solve(index+1, value + CI[index]));
    res = max(res,solve(index+1, value - CI[index]));

    return dp[index][value] = res;
}

class ChangingSounds{
public:
    int maxFinal(vector<int>, int, int);
};

int ChangingSounds::maxFinal(vector<int> changeIntervals, int beginLevel, int maxLevel){
    memset(dp, -1, sizeof(dp));
    CI = changeIntervals;
    maxVol = maxLevel;
    return solve(0, beginLevel);
}
