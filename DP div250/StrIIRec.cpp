#include<iostream>
#include<algorithm>

using namespace std;

int inv(string minStr){
	int toatl_inv = 0;
	for(int i = 0; i < minStr.size(); ++i){
		for(int j = i+1; j < minStr.size(); ++j){
			if(minStr[i] > minStr[j])
				toatl_inv++;
		}
	}
	return toatl_inv;
}

string next(string minStr){
	string prev, curr;
	prev = minStr;

	next_permutation(minStr.begin(), minStr.end());

	if(prev < curr)	
		return curr;
	else
		return prev;

}

class StrIIRec{
public:
	string recovstr(int, int, string);
};

string StrIIRec::recovstr(int n , int minInv, string minStr){
	for(int i = 0; i < n; ++i){
		char ch = 'a' + i; 
		if(!count(minStr.begin(), minStr.end(), ch)) // the char which isn't in the string
			minStr += ch;
	}

	string s = minStr;
	while(inv(s) < minInv)
		s = next(s);

	return s;
}
