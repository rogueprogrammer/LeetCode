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
#include <map>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
//Find the number of ways to use k integers to add up to sum

//O(sum^2 * k) dp solution:
int NumberOfWays(const int sum, const int k){
	vector<vector<int>> dp(k + 1, vector<int> (sum + 1));
	for (int i = 0; i <= k; ++i){

		for (int j = 0; j <= sum; ++j){

			if (i == 0){
				dp[i][j] = 0;
			}
			else if (j == 0){
				if (i == 1) {
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = 0;
				}
			}
			else if (i == 1) {
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = 0;
				for (int r = 0; r <= j; ++r){
					dp[i][j] += dp[i - 1][r];
				}
				/*int limit = j;
				if (i > 2){
					limit = j - 1;
				}
				
			   for (int r = 0; r <= limit; ++r){
					dp[i][j] += dp[i - 1][r];
			   }*/
				
			}
		}
	}
	//DEBUG_2D(dp);
	return dp[k][sum];
}


int main(){
	
	cout << NumberOfWays(5, 2) << endl;
	cout << NumberOfWays(5, 3) << endl;
	cout << NumberOfWays(5, 4) << endl;
	return 0;
}
