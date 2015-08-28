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

//https://leetcode.com/problems/palindrome-partitioning-ii/
//Partition the string such that every substring is a palindrome. Compute minimum number of cuts to make this happen.
// O(n^2) DP algorithm

//Build  a look up table IP, that tells if s[i, ..., j] is a palindrome
vector<vector<bool>> BuildIsPalindromeLookupTable(string s){
	vector<vector<bool>> IP(s.size(), vector<bool>(s.size()));
	int len = s.size(); 
	for (int i = 0; i < len; ++i){
		IP[i][i] = 1;
		if (i != len - 1){
			IP[i][i + 1] = (s[i] == s[i + 1]);
		}
	}

	//build the rest bottom-up:
	for (int i = len - 2; i >= 0; --i){
		for (int j = i + 2; j <= len - 1; ++j){
			IP[i][j] = (s[i] == s[j]) && IP[i + 1][j - 1];
		}
	}
	return IP;
}

//let DP[i] = min num of cuts from s[0...i]
int minCut(string s){
	vector<vector<bool>> IP = BuildIsPalindromeLookupTable(s);
	vector<int> DP(s.size());
	DP[0] = 0;
	for (int i = 1; i < s.size(); ++i){
		DP[i] = DP[i-1]+1;
		for (int j = i - 1; j >= 0; --j){
			if (IP[j][i]){
				DP[i] = min(DP[i], DP[j]);
			}
		}

	}
	//DEBUG_1D(DP);
	return DP[s.size() - 1];
}


int main(){

	//vector<vector<bool>> IP = BuildIsPalindromeLookupTable("20102");
	//vector<vector<bool>> IP = BuildIsPalindromeLookupTable("aba");
	//vector<vector<bool>> IP = BuildIsPalindromeLookupTable("2002");
	//vector<vector<bool>> IP = BuildIsPalindromeLookupTable("200201");
	//DEBUG_2D(IP);

	cout << minCut("aba") << endl; //0
	cout << minCut("aabcd") << endl; //3
	cout << minCut("aabcb") << endl; //1
	cout << minCut("2002002") << endl; //0
	cout << minCut("30040031") << endl; //1
	return 0;
}

