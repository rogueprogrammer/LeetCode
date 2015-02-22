#include "header.h"

//Given an amount, and a vector v contianing coin denomination values, finds the minimum # of coins to make the amount.
int CoinChange(int amount, vector<int> v){

	vector<int> C(amount);
	C[0] = 0;
	for (int i = 1; i < amount; ++i){
		
		int num_coins = 0;
		int min_num_coins = INT_MAX;
		for (int j = 0; j < v.size(); ++j){
			if (i < v[j]) break;
			num_coins = C[i - v[j]] + 1;
			if (num_coins < min_num_coins) min_num_coins = num_coins;
		}
		C[i] = min_num_coins;
	}
	return C[amount - 1];
}
