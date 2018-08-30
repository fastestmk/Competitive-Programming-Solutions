#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cal(int a, int b){
    int dis = 0, p = 0, q = 0;
    if( (a >= 0 && b >= 0) || (a < 0 && b < 0) ){
        p = abs(a), q = abs(b);
        dis += abs(p-q);
    }

    if( (a < 0 && b >= 0) || (a >= 0 && b < 0) ){
        p = abs(a), q = abs(b);
        dis += p+q;
    } 
    return dis;
}

class EvenRoute{
public:
    string isItPossible(vector<int>, vector<int>, int);
};

string EvenRoute::isItPossible(vector<int> x, vector<int> y, int wantedParity){
    int n = x.size();
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int s = 0, t = 0;
    int res = 0;
    for(int i = 0; i < n; ++i){
        int a = x[i], b = y[i];
        res += cal(s, a);
        res += cal(t, b);
        s = x[i], t = y[i]; 
    }

    if( (res%2==0) && wantedParity == 0)
        return "CAN";
    if( (res%2!=0) && wantedParity == 1)
        return "CAN";

    return "CANNOT";
}
