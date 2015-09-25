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

//https://leetcode.com/problems/maximal-square/
//let DP[i][j] = max square size from any point to matrix[i][j]
int maximalSquare(vector<vector<char>>& matrix) {
	
	int m = matrix.size(); int n = matrix[0].size();
	
	vector<vector<int>> DP(m, vector<int>(n));
	DP[0][0] = matrix[0][0] - '0';
	int max_square = DP[0][0];
	
	//base case - 1st row
	for (int j = 0; j < n; ++j){
		DP[0][j] = matrix[0][j] - '0';
		max_square = max(max_square, DP[0][j]);
	}

	//base case - 1st col
	for (int i = 0; i < m; ++i){
		DP[i][0] = matrix[i][0] - '0';
		max_square = max(max_square, DP[i][0]);
	}
	
	for (int i = 1; i < m; ++i){
		for (int j = 1; j < n; ++j){
			int cur = matrix[i][j] - '0';
			int up = matrix[i - 1][j] - '0'; int left = matrix[i][j - 1] - '0'; int left_diag = matrix[i - 1][j - 1] - '0';
			if ((cur == 1) && (up == left == left_diag != 0)){
				int dp_up = DP[i - 1][j - 1];
				DP[i][j] = pow((sqrt(dp_up) + 1), 2);
			}
			else{
				DP[i][j] = cur;
			}
			max_square = max(max_square, DP[i][j]);
		}
	}
	//DEBUG_2D(DP);
	return max_square;
}


int main(){
	
	vector<vector<char>> M = {
		{ '1', '0', '0' },
		{ '1', '1', '1'},
		{ '1', '1', '1' },
		{ '1', '1', '1' }
	}; //9

	/*vector<vector<char>> M = {
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },  //1 0 1 1 1
		{ '1', '1', '1', '1', '1' }, //1 1 1 1 1
		{ '1', '0', '0', '1', '0' } //1 0 0 1 0
	};*/ //4
	cout << maximalSquare(M) << endl;
	return 0;
}

