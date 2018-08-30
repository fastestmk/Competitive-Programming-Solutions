#include<iostream>
#include<cstring>

using namespace std;

int n;
int dp[55][55][55];

int solve(int left, int right, int next, string str){
	if(dp[left][right][next] != -1)
		return dp[left][right][next];

	int res = 0;
	for(int i = left; i <= right; ++i){
		for(int j = max(next, i+1); j < n; j++){
			if(str[i] == str[j]){
				res = max(res, 2+solve(i+1, min(right, j-1), j+1, str));
			}
		}
	}

	return dp[left][right][next] = res;
}


class RepeatStringEasy{
public:
	int maximalLength(string);
};

int RepeatStringEasy::maximalLength(string str){
	memset(dp, -1, sizeof(dp));
	n = str.size();
	return solve(0, n-1, 0, str);
}
