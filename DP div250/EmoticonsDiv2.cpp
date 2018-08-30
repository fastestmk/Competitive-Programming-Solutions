#include<iostream>
#include<vector>

using namespace std;

class EmoticonsDiv2{
public:
    int printSmiles(int);
};

int EmoticonsDiv2::printSmiles(int smiles){

    vector<int> vec;
    for(int i = 2; i*i<=smiles; ){
        if(smiles%i==0){
            smiles /= i;
            vec.push_back(i);
        }
        else
            i++;    
    }
    if(smiles > 2)
        vec.push_back(smiles);

    int res = 0;
    for(int i = 0; i < vec.size(); ++i){
        res += vec[i];
    }
    return res;
}
