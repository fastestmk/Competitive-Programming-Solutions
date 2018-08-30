#include<iostream>

using namespace std;

long totalCars[100];

class TrafficCongestionDivTwo{
public:
	long theMinCars(int treeHeight);
};

long TrafficCongestionDivTwo::theMinCars(int treeHeight){
	totalCars[0] = 1;
	totalCars[1] = 1;

	for(int i = 2; i <= treeHeight; ++i){
		totalCars[i] = 1;
		for(int j = 0; j <= i-2; ++j){
			totalCars[i] += 2*totalCars[j];
		}
	}

	return totalCars[treeHeight];
}
