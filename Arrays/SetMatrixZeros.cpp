#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.*/

void setZeroes(vector<vector<int>> &matrix){
	int num_rows = matrix.size();
	int num_cols = matrix[0].size();

	bool *rows = new bool[num_rows];
	bool* cols = new bool[num_cols];
	rows = { false };
	cols = { false };

	for (int i = 0; i < num_rows; ++i){
		for (int j = 0; j < num_cols; ++j){
			if (matrix[i][j] == 0){
				rows[i] = true; cols[j] = true;
			}
		}
	}

	for (int i = 0; i < num_rows; ++i){
		for (int j = 0; j < num_cols; ++j){
			if (rows[i] || cols[j]){
				matrix[i][j] = 0;
			}
		}

	}
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
