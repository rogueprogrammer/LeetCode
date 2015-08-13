#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/minimum-path-sum/

/*
Let DP[i][j] be the minimum path sum from [0,0] to [i,j]
example input grid:
1,2,-1
5,-10,4
2,1,7

corresponding DP:
1,3,2
6,-7,-3
8,-6,1

DP[i][j] = min{ DP[i-1][j], DP[i][j-1] } + grid[i][j]
*/

#define DEBUG_VEC(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}


int minPathSum(vector<vector<int>>& grid) {
	int num_rows = grid.size();
	int num_cols = grid[0].size();
	vector<vector<int>> dp(num_rows, vector<int>(num_cols));

	for (int i = 0; i < num_rows; ++i){

		for (int j = 0; j < num_cols; ++j){
			if (i == 0 && j == 0) dp[i][j] = grid[0][0]; 
			else if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
			else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
			else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			
		}

	}

	//DEBUG_VEC(dp);
	return dp[num_rows - 1][num_cols - 1];
}


