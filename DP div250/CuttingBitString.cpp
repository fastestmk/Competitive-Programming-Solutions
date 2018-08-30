#include<iostream>

using namespace std;

bool check(string str){
    if(str[0] == '0') // segment must not has leading zero
        return false;
    int n = 0;
    for(int i = 0; i < str.length(); ++i){
        n = n*2 + (str[i] == '1');
    }

    while(n%5==0){
        n /= 5;
    }

    return n == 1;
}

class CuttingBitString{
public:
    int getmin(string str);
};

int CuttingBitString::getmin(string str){
    int n = str.size();
    int dp[100];

    for(int i = 0; i < n; ++i){
        dp[i] = -1;
        if(check(str.substr(0, i+1))){
            dp[i] = 1;
        }
        else{
            for(int j = 1; j <= i; ++j){
                if(check(str.substr(j, i-j+1)) && dp[j-1] != -1){
                    if(dp[i] == -1 || dp[i] > dp[j-1] + 1){
                        dp[i] = dp[j-1]+1;
                    }
                }
            }
        }

    }
    return dp[n-1];
}

// string str = "101101"