#include<iostream>
#include<vector>

using namespace std;

int frq[12];
int zero[12], one[12];
vector<int> vec;
class NumberofFiboCalls{
public:
	vector<int> fiboCallsMade(int);
};

vector<int> NumberofFiboCalls::fiboCallsMade(int n){
	

	zero[0] = 1, zero[1] = 0;
	one[0] = 0, one[1] = 1;

	for(int i = 2; i <= n; ++i){
		zero[i] = zero[i-1]+zero[i-2];
		one[i] = one[i-1]+one[i-2];
	}

	vec[0] = zero[n];
	vec[1] = one[n];
	return vec;
}
