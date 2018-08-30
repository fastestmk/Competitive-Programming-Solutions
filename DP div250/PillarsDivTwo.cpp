#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double dp[105][105];

class PillarsDivTwo{
public:
	double maximalLength(vector<int>, int);
};

double PillarsDivTwo::maximalLength(vector<int> height, int w){
	int n = height.size();
	double res = 0.0;
	for(int i = 1; i < n; ++i){
		for(int j = 1; j <= height[i]; ++j){
			for(int k = 1; k <= height[i-1]; ++k){
				dp[i][j] = max(dp[i][j], dp[i-1][k] + sqrt(w*w + (k-j) * (k-j)));
				res = max(res, dp[i][j]);
			}
		}
	}
	return res;
}
