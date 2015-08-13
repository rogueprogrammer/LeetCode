#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/unique-paths/


#define DEBUG_VEC(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}


int uniquePaths(int m, int n){
	vector<vector<int>> dp(m, vector<int>(n));

	for (int i = 0; i < m; ++i){
		dp[i][0] = 1;
	}
	for (int i = 0; i < n; ++i){
		dp[0][i] = 1;
	}


	for (int i = 1; i < m; ++i){
		for (int j = 1; j < n; ++j){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	DEBUG_VEC(dp);
	return dp[m - 1][n - 1];

}
