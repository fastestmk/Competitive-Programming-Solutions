#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int DP[65][65][65];
int dp(int a, int b, int c){
    if(a <= 0)
        a = 0;
    if(b <= 0)
        b = 0;
    if(c <= 0)
        c = 0;

    if(a == 0 && b == 0 && c == 0)
        return 0;

    //base case
    if(DP[a][b][c] != -1)
        return DP[a][b][c];

    int first = 1+dp(a-1, b-3, c-9);
    int second = 1+dp(a-1, b-9, c-3);
    int three = 1+dp(a-3, b-1, c-9);
    int four = 1+dp(a-3, b-9, c-1);
    int five = 1+dp(a-9, b-1, c-3);
    int six = 1+dp(a-9, b-3, c-1);

    int res_1 = min(first, second);
    int res_2 = min(three, four);
    int res_3 = min(five, six);

    return DP[a][b][c] = min(min(res_1, res_2), res_3);
}

class MutaliskEasy{
public:
    int minimalAttacks(vector<int>);
};

int MutaliskEasy::minimalAttacks(vector<int> x){
    memset(DP, -1, sizeof(DP));
    int a, b = 0, c = 0;
    a = x[0];
    if(x.size() >= 2)
        b = x[1];
    if(x.size() == 3)
        c = x[2];

    return dp(a, b, c);               
}
