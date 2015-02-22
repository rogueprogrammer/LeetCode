#include "header.h"

int LongestCommonPalindromeSubstring(string x){
	int n = x.size();
	vector<vector<int>> L(n, vector<int> (n));

	for (int i = 0; i < n; ++i)	L[i][i] = 1;

	for (int len = 2; len <= n; ++len){

		for (int i = 0; i < n - len + 1; ++i){
			int j = i + len - 1;
			if ((x[i] == x[j]) && len == 2) L[i][j] = 2;
			if (x[i] == x[j]) L[i][j] = L[i + 1][j - 1] + 2;
			else L[i][j] = std::max(L[i + 1][j], L[i][j - 1]);
		}

	}
	
	return L[0][n-1];
}
