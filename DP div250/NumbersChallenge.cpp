#include<iostream>
#include<vector>

using namespace std;

vector<int> vis(21*100000);

class NumbersChallenge{
public:
	int MinNumber(vector<int>);
};

int NumbersChallenge::MinNumber(vector<int> S){
	int n = S.size();
	int total = 1 << n;

	for(int i = 1; i < total; ++i){
		int sum = 0;

		for(int j = 0; j < n; ++j){
			if(i & (1 << j)){
				sum += S[j];
			}
		}
		vis[sum] = 1;
		cout << sum << endl;

	}

	for(int i = 1; i < vis.size(); ++i){
		if(vis[i] == 0) 
			return i; // if not in array return arr[last+1] element
	}
}
