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

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//update - this is a working solution (passed all test cases)
//O(n) algorithm 

int maxProfit(vector<int>& prices) {
	if (prices.size() == 0) return 0;
	vector<int> t1(prices.size()); //t1 = profit from day 0, ..., i 
	vector<int> t2(prices.size()); //t2 = profit from day i, ... n-1 (n == number of stock prices)

	t1[0] = 0;
	int lowest = prices[0];
	for (int i = 1; i < prices.size(); ++i){
		int curPrice = prices[i];
		if (curPrice < lowest){
			lowest = curPrice;
			t1[i] = 0;
		}
		else{
			t1[i] = curPrice - lowest;
		}
	}
	//DEBUG_1D(t1);

	t2[prices.size() - 1] = 0;
	int highest = prices[prices.size() - 1];
	int profit = t1[prices.size() - 1];
	int t2_highest = 0;
	for (int i = prices.size() - 2; i >= 0; --i){
		int curPrice = prices[i];
		if (curPrice > highest){
			highest = curPrice; 
			t2[i] = 0;
		}
		else{
			t2[i] = highest - prices[i];
		}
		if (t2[i] > t2_highest){
			t2_highest = t2[i];
		}
		profit = max(profit, t2_highest + t1[i]);
	}
	//DEBUG_1D(t2);
	return profit;
}


int main(){
	
	vector<int> prices = { 3, 10, 22, 15, 6, 20, 26 };
	cout << maxProfit(prices) << endl; //39
	return 0;
}
