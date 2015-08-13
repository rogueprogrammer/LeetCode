#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define DEBUG_VEC(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

//https://leetcode.com/problems/unique-paths-ii/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int num_rows = obstacleGrid.size();
	int num_cols = obstacleGrid[0].size();
	vector<vector<int>> dp(num_rows, vector<int>(num_cols));

	dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
	for (int i = 1; i < num_cols; ++i){
		dp[0][i] = (obstacleGrid[0][i] != 1) ? dp[0][i - 1] : 0;
	}
	for (int i = 1; i < num_rows; ++i){
		dp[i][0] = (obstacleGrid[i][0] != 1) ? dp[i-1][0] : 0;
	}

	for (int i = 1; i < num_rows; ++i){
		for (int j = 1; j < num_cols; ++j){
			dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];
		}
	}
	DEBUG_VEC(dp);

	return dp[num_rows - 1][num_cols - 1];
}
