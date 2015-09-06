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
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
//https://leetcode.com/submissions/detail/39007560/

int maxProfit(vector<int>& prices) {
	if (prices.size() == 0) return 0;
	int lowestPrice = prices[0];
	int largestProfit = 0;

	for (int i = 1; i < prices.size(); ++i){
		int curPrice = prices[i];
		if (curPrice >= lowestPrice){
			largestProfit = max(largestProfit, curPrice - lowestPrice);
		}
		else{
			lowestPrice = curPrice;
		}
	}
	return largestProfit;
}


int main(){
	vector<int> prices = { 5, 3, 10, 13, 8, 2, 4, 20 };
	//vector<int> prices = { 5, 3, 2, 1 };
	cout << maxProfit(prices) << endl;
	return 0;
}



