#include<iostream>
#include<vector>

using namespace std;

class ColorfulRoad{
public:
    int getMin(string);
};

int ColorfulRoad::getMin(string Road){
    int n = Road.length();
    vector<int> dp(n, -1);
    dp[0] = 0; 
    for(int i = 0; i < n; ++i){
        if(dp[i]>=0) // notice this
        for(int j = i+1; j < n; ++j){
            if((Road[i] == 'R' && Road[j] == 'G') || (Road[i] == 'G' && Road[j] == 'B') ||(Road[i] == 'B' && Road[j] == 'R')){
                if(dp[j] == -1 || dp[j] > dp[i] + (j-i)*(j-i)){
                    dp[j] = dp[i] + (j-i)*(j-i);
                }
            }
        }
    }
    return dp[n-1];
}

int main(){
    string str;
    cin >> str;

    ColorfulRoad obj;
    cout << obj.getMin(str);
}
