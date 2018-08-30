#include<iostream>

using namespace std;

#define ll long long
int dp[100];
int cal[100] = {0};

class HandsShaking{
public:
	ll countPerfect(int);
};

ll HandsShaking::countPerfect(int n){
	if(n == 0 || n == 2)
		return 1;
	if(cal[n])
		return dp[n];

	ll res = 0;
	for(int i = 0; n-i-2>=0; i+=2){
		res += countPerfect(i)*countPerfect(n-i-2);
	}

	cal[n] = 1;
	dp[n] = res;
	return res;
}
