#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;



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



//2. Given a number WAP to find a number closet to it and is a power of 2 e.g.i / p 7 o / p 8.

bool IsPowerof2(int x){
	while (x > 1){
		if (x % 2 != 0){
			return false;
		}
		x /= 2;
	}
	return true;
}


int ClosestPowerof2(int x){
	int greaterthanx = 0;

	//closest power of 2 greater than x
	for (int i = x;; ++i){
		if (IsPowerof2(i)){
			greaterthanx = i; 
			break;
		}
	}

	int lessthanx = 0;

	//closest power of 2 less than x
	for (int i = x; i >= 1; --i){
		if (IsPowerof2(i)){
			lessthanx = i;
			break;
		}
	}

	return (abs(greaterthanx - x) <= abs(lessthanx - x)) ? greaterthanx : lessthanx;
}



//3. 

/*
There are a row of houses, each house can be painted with three colors red, blue and green.
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color. 
You have to paint the houses with minimum cost. How would you do it?
*/

//http://stackoverflow.com/questions/24646122/3-houses-and-minimum-cost-of-painting


vector<int> red_cost = { 5, 3, 7 };
vector<int> green_cost = { 2, 4, 6 };
vector<int> blue_cost = { 3, 1, 9 };

/*
Let LC(n, c) be the cheapest painting of the first n houses, where the last house is colored c 
Let Cost(c, k) be the cost of painting the kth house as c
LC(n,c) = Cost(C, n) + min(LC(n-1, _C)) st _C != C
*/


int MinCostHousePainting(vector<int> r, vector<int> g, vector<int> b){
	int res = 0;
	int num_houses = r.size();

	vector<vector<int>> Cost(3, vector<int>(num_houses));
	for (int i = 0; i < r.size(); ++i){ Cost[0][i] = r[i]; }
	for (int i = 0; i < g.size(); ++i){ Cost[1][i] = g[i]; }
	for (int i = 0; i < b.size(); ++i){ Cost[2][i] = b[i]; }

	vector<vector<int>> LC(num_houses, vector<int>(3));
	int minPrev = INT_MAX;
	for (int i = 0; i < num_houses; ++i){
		
		for (int j = 0; j < 3; ++j){
			if (i == 0){ LC[i][j] = Cost[j][i]; continue; }

			for (int k = 0; k < 3; ++k){
				if (k == j) continue;
				if (LC[i - 1][k] < minPrev){
					minPrev = LC[i - 1][k];
				}
			}
		   LC[i][j] = minPrev + Cost[j][i];
		   minPrev = INT_MAX;
		}
	}

	int min = INT_MAX;

	for (int i = 0; i < 3; ++i){
		if (LC[num_houses - 1][i] < min) min = LC[num_houses - 1][i];
	}

	return min;
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
	//vector<vector<int>> C = Multiply2Matrices(A, B);
	//PrintMatrix(C);


	//cout << MinCostHousePainting(red_cost, green_cost, blue_cost) << endl;

	cout << ClosestPowerof2(400) << endl;

}

