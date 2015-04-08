#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <Queue>
using namespace std;


bool GetElementToLeft(vector<vector<int>> matrix, int row, int col, int& val){
	if (row == 0 && col == 0) return false;
	int num_cols = matrix[0].size();
	if (col >= 1) val = matrix[row][col - 1];
	else{
		if (row > 0) val = matrix[row - 1][num_cols - 1];
	}
	return true;
}


bool GetElementAbove(vector<vector<int>> matrix, int row, int col, int& val){
	if (row == 0) return false;
	val = matrix[row - 1][col];
	return true;
}




int LongestIncreasingSubsequenceinMatrix(vector<vector<int>> matrix){
	int num_rows = matrix.size();
	int num_cols = matrix[0].size();

	vector<vector<int>> A(num_rows, vector<int>(num_cols));
	
	int max_acc = INT_MIN;

	for (int i = 0; i < num_rows; ++i){

		for (int j = 0; j < num_cols; ++j){
			if ((i == 0) && (j == 0)) A[i][j] = 0;
			int elem_left; int elem_above;
			A[i][j] = 1;
			if (GetElementAbove(matrix, i, j, elem_above)){
				if (elem_above < matrix[i][j]) A[i][j] = A[i - 1][j] + 1;
			}
			if (GetElementToLeft(matrix, i, j, elem_left)){
				if (elem_left < matrix[i][j]){ //A[i][j] = max(A[i][j], A[i][j - 1] + 1);
					if (j > 0){
						A[i][j] = max(A[i][j], A[i][j - 1] + 1);
					}
					else{
						A[i][j] = max(A[i][j], A[i-1][num_cols-1] + 1);
					}

				}
			}
			if (A[i][j] > max_acc) max_acc = A[i][j];

		}
	}
	
	return max_acc;

}
