#include<iostream>
#include<vector>

using namespace std;

class EllysCheckers{
public:
	string getWinner(string);
};


string EllysCheckers::getWinner(string board){
	
	int res = 0;
	for(int i = 0; i < board.length(); ++i){
		if(board[i] == 'o'){
			res += board.length()-i-1;
		}
	}	

	return (res&1) ? "YES" : "NO";
}	
