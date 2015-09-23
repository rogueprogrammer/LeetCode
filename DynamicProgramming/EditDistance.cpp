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

//https://leetcode.com/problems/edit-distance/
//let DP[i][j] = min number of operations (distance) from word1[0, .., i] to word2[0, .., j]

int minDistance(string word1, string word2){
	int rows = word1.size() ; int cols = word2.size() ;
	vector<vector<int>> DP(rows, vector<int>(cols));

	//Base case - 1st row
	bool seen = false;
	for (int i = 0; i < cols; ++i){
		if (!seen && word1[0] == word2[i]){
			seen = true;
			if (i == 0){
				DP[0][i] = 0;
			}
			else{
				DP[0][i] = DP[0][i - 1];
			}
		}
		else{
			if (i == 0){
				DP[0][i] = 1;
			}
			else{
				DP[0][i] = DP[0][i - 1] + 1;
			}
		}
	}

	//Base case - 1st col
	seen = word1[0] == word2[0];
	for (int i = 1; i < rows; ++i){
		if (!seen && word2[0] == word1[i]){
			seen = true;
			DP[i][0] = DP[i - 1][0];
		}
		else{
			DP[i][0] = DP[i - 1][0] + 1;
		}
	}

	//Build the rest top down:
	for (int i = 1; i < rows; ++i){
		for (int j = 1; j < cols; ++j){
			int del = DP[i - 1][j] + 1;
			int ins = DP[i][j - 1] + 1;
			int rep = DP[i - 1][j - 1] + (word1[i] != word2[j]);
			DP[i][j] = min(min(del, ins),  rep);
		}
	}
	DEBUG_2D(DP);
	return DP[rows-1][cols-1];
}

int main(){
	
	//cout << minDistance("ABB", "ABE") << endl;
	string word1 = "APCLE"; //"APPLE"
	string word2 = "ACE";

	cout << minDistance(word2, word1) << endl;
	
	return 0;
}
