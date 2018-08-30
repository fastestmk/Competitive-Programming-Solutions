#include<iostream>
#include<vector>

using namespace std;

const int mod = 998244353;
int dp[303][10007];

class IncreasingSequencesEasy{
public:
	int count(vector<int>, vector<int>);
};

int IncreasingSequencesEasy::count(vector<int> L, vector<int> R){
	for(int i = 0; i <= 10006; ++i){
		dp[0][i] = 1;
	}
	for(int i = 1; i <= L.size(); ++i){
		for(int j = L[i-1]; j <= R[i-1]; ++j){
			dp[i][j] = dp[i-1][j-1];
		}	
		for(int j = 1; j <= 10006; ++j){
			dp[i][j] += dp[i][j-1];
			if(dp[i][j] >= mod){
				dp[i][j] -= mod;
				dp[i][j] %= mod;
			}
		}
	}
	return dp[L.size()][10006];
}
