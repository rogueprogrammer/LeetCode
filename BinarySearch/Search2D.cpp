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
//https://leetcode.com/problems/search-a-2d-matrix/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int rows = matrix.size(); int cols = matrix[0].size();

	int low = 0; int hi = (rows * cols) - 1;

	while (low <= hi){
		int mid = (low + hi) / 2;
		int x = mid / cols;
		int y = mid % cols;
		if (matrix[x][y] == target) return true;
		else if (matrix[x][y] < target) low = mid + 1;
		else hi = mid - 1;
	}

	return false;
}


int main(){
	

	vector<vector<int>> M = {
		{ 1, 4 },
		{ 2, 5 }
	};
	cout << searchMatrix(M, 2) << endl;
	return 0;
}
