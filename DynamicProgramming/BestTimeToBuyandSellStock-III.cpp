#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;
typedef int int64;
//doesn't pass last test case, not fully perfect, but close enough, get back to this later
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

int maxProfit(vector<int>& prices) {
	if (prices.size() == 0) return 0;
	vector<int> profit_sell_i(prices.size());
	vector<int> profit_buy_i(prices.size());
	
	int index_max_s = 0;
	int max_s = profit_sell_i[0];
	int min_price = prices[0];
	profit_sell_i[0] = 0;
	for (int i = 1; i < prices.size(); ++i){
		int curPrice = prices[i];
		
		
		if (curPrice < min_price){
			profit_sell_i[i] = 0;
			min_price = curPrice;
		}
		else{
			profit_sell_i[i] =  curPrice - min_price;
		}

		if (profit_sell_i[i] > max_s){
			index_max_s = i;
			max_s = profit_sell_i[i];
		}
	}
	//DEBUG_1D(profit_sell_i); cout << max_s << endl; cout << index_max_s << endl;
	int index_max_b = prices.size() - 1;
	profit_buy_i[prices.size() - 1] = 0;
	int max_b_price = prices[prices.size()-1];
	int max_b = profit_buy_i[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; --i){
		int curPrice = prices[i];
		if (curPrice > max_b_price){
			max_b_price = curPrice;
			profit_buy_i[i] = 0;
		}
		else{
			profit_buy_i[i] = max_b_price - curPrice;
		}
		if (profit_buy_i[i] > max_b){
			index_max_b = i;
			max_b = profit_buy_i[i];
		}
	}
	//DEBUG_1D(profit_buy_i);
	//cout << max_b << endl;
	//cout << index_max_b << endl;

	
	int max_b_p = 0;
	//after index_max_s, find largest profit val in profit_buy = max_b_p
	if (index_max_s < prices.size() - 1){
		max_b_p = profit_buy_i[index_max_s + 1];
		for (int i = index_max_s+2; i < prices.size(); ++i){
			max_b_p = max(max_b_p, profit_buy_i[i]);
		}
	}
	int profit1 = max_s + max_b_p;
	//cout << profit1 << endl;


	int max_s_p = 0;
	//before index_max_b, find largest profit val in profit_sell = max_s_p
	if (index_max_b - 1 >= 0){
		max_s_p = profit_sell_i[index_max_b - 1];
		for (int i = index_max_b - 2; i >= 0; --i){
			max_s_p = max(max_s_p, profit_sell_i[i]);
		}
	}
	int profit2 = max_b + max_s_p;

	return max(profit1, profit2);

}

int main(){

	//vector<int> prices = { 0, 40, 13, 8, 12, 13, 20, 30 }; //62
	//vector<int> prices = { 2, 4, 8, 12, 18, 3, 5, 1, 28, 0, 40 }; //67
	//vector<int> prices = { 2, 1, 2, 0, 1 }; //2
  vector<int> prices = {6, 1, 3, 2, 4, 7}; not working?
	cout << maxProfit(prices) << endl;

	return 0;
}
