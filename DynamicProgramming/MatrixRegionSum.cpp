#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;
typedef int int64;

/*
Problem: Matrix Region Sum.
Source: http://www.ardendertat.com/2011/09/20/programming-interview-questions-2-matrix-region-sum/ (My solution is different from the author's)
Given {matrix of numbers, start row, start col, end row, end col} , find the sum of the numbers in the region of the matrix.
This can easily be solved in O(mn) naiive brute force, where m is number of rows, n is number of cols.

The algorithm below creates a helper, precomputed matrix in O(mn), once. 
It caches the accumulated sums from A[0][0] to A[i][j] in a matrix called DP[i][j].
The real power of the algorithm is that if you have a large matrix, and want to keep finding sums of different regions in the matrix, you could precompute
DP once, and keep on using it to compute the region sum in O(1) time. Thus, the algorithm has the potential to be O(1) if the precompute method to fill out
DP is only done once and used for the later computations.
*/

int MatrixRegionSum(vector<vector<int>>& A, int srow, int erow, int scol, int ecol){
	vector<vector<int>> DP(A.size(), vector<int>(A[0].size()));
	int numRows = A.size(); int numCols = A[0].size();
	for (int i = 0; i < numRows; ++i){
		for (int j = 0; j < numCols; ++j){
			if ((i == j) && (j== 0)){
				DP[i][j] = A[i][j];
			}
			else if (i == 0){
				DP[i][j] = DP[i][j - 1] + A[i][j];
			}
			else if (j == 0){
				DP[i][j] = DP[i - 1][j] + A[i][j];
			}
			else{
				DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + A[i][j];
			}
		}
	}
	//DEBUG_2D(DP);

	int sum = DP[erow][ecol] ;
	if ((srow == erow) && (scol == ecol) && (srow == 0) && (ecol == 0)){
		return sum;
	}
	//if something to the left of region, subtract it out
	if (scol > 0){
		sum -= A[srow][scol - 1];
		if (srow != erow){
			sum -= A[erow][scol - 1];
		}
	}
	//if something above region, subtract it out
	if (srow > 0){
		sum -= A[srow - 1][scol];
		if (scol != ecol){
			sum -= A[srow - 1][ecol];
		}
	}
	
	return sum;
}

int main(){
	vector<vector<int>> A = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
		{10, 11, 12}
	};
	//srow, erow, scol, ecol
	cout <<MatrixRegionSum(A, 0, 1, 1, 2) << endl;

	return 0;
}
