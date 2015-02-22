#include "header.h"


//Given 2 sequences, finds the length of the longest common subsequence present in both of them. A subsequence is a sequence
//that appears in the same relative order, but not necessarily contiguous. 
//EG: "COMMONPAL" and "MONDAY" have largest common subsequence to be "MONA" of length 4.

int LongestCommonSubsequence(string x, string y){

	vector<vector<int>> L(x.size() + 1, vector<int>(y.size() + 1));
	for (int i = 0; i <= x.size(); ++i){

		for (int j = 0; j <= y.size(); ++j){
			if (i == 0 || j == 0) L[i][j] = 0;
			else if (x[i] == y[j]) L[i][j] = 1 + L[i - 1][j - 1];
			else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	return L[x.size()][y.size()];
}
