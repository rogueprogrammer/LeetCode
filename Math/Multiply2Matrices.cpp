#include "header.h"

//1. Write a program(WAP) to multiply 2 matrices.

vector<vector<int>> Multiply2Matrices(vector<vector<int>> A, vector<vector<int>> B){

	int rows_A = A.size();  int cols_A = A[0].size();
	int rows_B = B.size();  int cols_B = B[0].size();

	if (cols_A != rows_B){
		cerr << "Multiplication not possible." << endl; exit(-1);
	}

	vector<vector<int>> C(rows_A, vector<int>(cols_B));
	for (int i = 0; i < rows_A; ++i){

		for (int j = 0; j < cols_B; ++j){
			C[i][j] = 0;
			for (int k = 0; k < rows_B; ++k){
				C[i][j] += A[i][k] * B[k][j];
			}

		}

	}
	return C;
}


void PrintMatrix(vector<vector<int>> A){
	int rows = A.size();
	int cols = A[0].size();

	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}

}



void main(){

	vector<vector<int>> A = {
			{1, 2, 3},
			{4, 5, 6}
	};


	vector<vector<int>> B= {
			{ 1, 4, 5 },
			{ 2, 6, 7 },
			{ 3, 8, 9 }
	};
	vector<vector<int>> C = Multiply2Matrices(A, B);
	PrintMatrix(C);
}
