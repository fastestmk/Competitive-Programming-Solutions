#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[55];
string s;
vector<string> str;

int count_diff(int start, int next){
	int count = 0;
	for(int i = 0; i < str[next].size(); ++i){
		if(str[next][i] != s[start+i])
			count++;
	}
	return count;
}

int check(int start, int next){
	string h = s.substr(start, str[next].size());
	string g = str[next];

	sort(h.begin(), h.end());
	sort(g.begin(), g.end());

	if(h == g)
		return 1;
	return 0;
}

int solve(int index){
	int res = 1 << 30;
	if(index == s.size()) 
		return 0;
	if(dp[index] != -1)
		return dp[index];

	for(int i = 0; i < str.size(); ++i){
		if(check(index, i)){
			res = min(res, solve(index+str[i].size()) + count_diff(index, i));
		}
	}

	return dp[index] = res;
}

class SentenceDecomposition{
public:
	int decompose(string, vector<string>);
};

int SentenceDecomposition::decompose(string senetence, vector<string> validWords){
	memset(dp, -1, sizeof(dp));
	s = senetence;
	str = validWords;
	int res = 1 << 30;
	res = solve(0);
	if(res == 1<<30)
		return -1;
	return res;
}
