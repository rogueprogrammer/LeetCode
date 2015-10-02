#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <math.h>
using namespace std;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;
typedef int int64;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//let DP[i][j] = max profit upto i transactions for stock price at j

int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	if ((n == 0) || (k == 0)) return 0;

	vector<vector<int>> DP(k, vector<int>(n));
	
	//first row
	DP[0][0] = 0;
	int minPrice = prices[0];
	for (int i = 1; i < n; ++i){
		DP[0][i] = max(DP[0][i - 1], prices[i] - minPrice);
		minPrice = min(minPrice, prices[i]);
	}
	//DEBUG_1D(DP[0]);
	
	for (int i = 1; i < k; ++i){
		minPrice = prices[0];
		int minPricePos = 0;
		for (int j = 0; j < n; ++j){
			if (j == 0){
				DP[i][j] = 0;
				continue;
			}
			if (prices[j] < minPrice){
				minPricePos = j;
				minPrice = prices[j];
			}
			int oneMoreTransaction = DP[i - 1][minPricePos] + (prices[j] - prices[minPricePos]);
			int prevTransaction = DP[i][j - 1];
			DP[i][j] = max(oneMoreTransaction, prevTransaction);
			if (DP[i][j] == prevTransaction){
				minPricePos = j;
				minPrice = prices[j];
			}
		}
	}
  //DEBUG_2D(DP);
	return DP[k-1][n-1];
}


int main(){
	
	//vector<int> prices = { 3, 10, 22, 15, 6, 20, 26 }; //39
	vector<int> prices = { 20, 26, 34, 5, 12, 24, 28 }; //37
	cout << maxProfit(3, prices) << endl;
	return 0;
}

