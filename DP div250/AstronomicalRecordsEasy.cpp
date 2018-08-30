#include<iostream>
#include<vector>
#include<set>

using namespace std;

class AstronomicalRecordsEasy{
public:
    int minimalPlanets(vector<int>, vector<int>);
};

int AstronomicalRecordsEasy::minimalPlanets(vector<int> A, vector<int> B){
    int res = A.size()+B.size();

    for(int i = 0; i < A.size(); ++i){
        for(int j = 0; j < B.size(); ++j){
            set<int> vis;
            for(int s = 0; s < A.size(); ++s){
                vis.insert(A[s]*B[j]);
            }
            for(int s = 0; s < B.size(); ++s){
                vis.insert(B[s]*A[i]);
            }

            res = min<int>(res, vis.size());
        }
    }

    return res;
}
