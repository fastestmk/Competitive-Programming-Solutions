#include<iostream>
#include<vector>

using namespace std;

class PalindromicSubstringsDiv2{
public:
    int count(vector<string>, vector<string>);
};

int PalindromicSubstringsDiv2::count(vector<string> S1, vector<string> S2){
    string res;
    for(int i = 0; i < S1.size(); ++i){
        res += S1[i];
    }

    for(int i = 0; i < S2.size(); ++i){
        res += S2[i];
    }
    int n = res.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i && j+i < n; ++j){
            if(res[i-j] == res[i+j])
                ans++;
            else
                break;
        }

        for(int j = 0; j <= i && j+i+1 < n; ++j){
            if(res[i-j] == res[i+j+1])
                ans++;
            else
                break;
        }
    }

    return ans;
}
