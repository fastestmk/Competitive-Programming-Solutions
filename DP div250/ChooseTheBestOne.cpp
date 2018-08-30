#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

#define ll long long 

class ChooseTheBestOne{
public:
	int countNumber(int N);
};

int ChooseTheBestOne::countNumber(int N){
	
	vector<int> ts(N);
	for(int i = 1; i <= N; ++i){
		ts[i-1] = i;
	}

	int i = 0;
	for(int t = 1; t < N; ++t){
		int m = ts.size();

		i = int(i+pow(t, 3)-1)%m;

		for(int j = i; j < m-1; ++j){
			ts[j] = ts[j+1];
		}

		ts.resize(m-1);
	}
	return ts[0];
}
