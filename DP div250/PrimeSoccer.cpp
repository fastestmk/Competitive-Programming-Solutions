#include<iostream>
#include<vector>

using namespace std;

void calc(int i, double acc, int goals, double pr, vector<double> &v){
	if(i == 18){
		v[goals]+=acc;
		return;
	}
	calc(i+1, acc*pr, goals+1, pr, v); // goal
	calc(i+1, acc*(1.0-pr), goals, pr, v); // not a goal
}

bool prime(int n){
	return (n == 2 || n==3 || n == 5 || n==7 || n==11 || n==13 || n==17);
}

class PrimeSoccer{
public:
	double getProbability(int, int);
};

double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB){
	vector<double> v1(20, 0.0), v2(20, 0.0);
	calc(0, 1.0, 0, skillOfTeamA/100.0, v1);
	calc(0, 1.0, 0, skillOfTeamB/100.0, v2);

	double ans = 0.0;
	for(int i = 0; i < 19; ++i){
		for(int j = 0; j < 19; ++j){
			if(prime(i) || prime(j)){
				ans += v1[i]*v2[j];
			}
		}
	}
	return ans;
}

int main(){
	int skillOfTeamA, skillOfTeamB;
	cin >> skillOfTeamA >> skillOfTeamB;
	PrimeSoccer obj;
	cout << obj.getProbability(skillOfTeamA, skillOfTeamB);
}	