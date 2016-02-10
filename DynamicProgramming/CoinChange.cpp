#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

int CoinChange(int amount, vector<int> C){
	int numCoins = C.size();
	vector<int> DP(amount + 1);
	DP[0] = 0;
	for (int i = 1; i <= amount; ++i){
		int minCoins = INT_MAX;
		for (int j = 0; j < C.size(); ++j){
			if (C[j] > i) break;
			if (i == C[j]) {
				minCoins = 1;
				break;
			}
			minCoins = min(minCoins, DP[i - C[j]] + DP[C[j]]);
		}
		DP[i] = minCoins;
	}
	return DP[amount];
}


int main(){

	int amount = 11;
	vector<int> v = { 1, 2, 5, 10 };
	cout << CoinChange(amount, v) << endl;

	return 0;
}



