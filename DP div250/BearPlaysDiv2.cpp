#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

bool vis[550][550];
int a, b, c;
vector<int> vec;

void solve(vector<int> vec){
    if(vis[vec[0]][vec[1]])
        return;
    vis[vec[0]][vec[1]] = true;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(vec[i] < vec[j]){
                int arr[] = {vec[i]*2, vec[j]-vec[i], vec[3-i-j]};
                
                vector<int> next(arr, arr + sizeof(arr)/sizeof(arr[0]));
                solve(next);
            }
        }
    }
}

class BearPlaysDiv2{
public:
    string equalPiles(int, int, int);
}; 

string BearPlaysDiv2::equalPiles(int A, int B, int C){
    a = A, b = B, c = C;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    int s = a+b+c;
    if(s%3 == 0){
        solve(vec);
        if(vis[s/3][s/3])
            return "possible";
    }
    return "impossible";
}
