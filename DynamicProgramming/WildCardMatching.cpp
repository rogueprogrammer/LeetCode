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

//https://leetcode.com/problems/wildcard-matching/

//let DP[i][j] = true if s[0,...,i] matches p[0,...,j], false otherwise
bool isMatch(string s, string p) {

	vector<vector<bool>> DP(s.size(), vector<bool>(p.size()));

	DP[0][0] = s[0] == p[0] || p[0] == '?' || p[0] == '*';
	//base case - first row:
	for (int j = 1; j < p.size(); ++j){
		DP[0][j] = 0;
	}

	//base case - first col:
	for (int i = 1; i < s.size(); ++i){
		DP[i][0] = p[0] == '*';
	}

	//build rest of DP top bottom:
	for (int i = 1; i < s.size(); ++i){
		for (int j = 1; j < p.size(); ++j){
			if (p[j] == '?'){
				DP[i][j] = DP[i - 1][j - 1];
			}
			else if (p[j] == '*'){
				DP[i][j] = DP[i - 1][j - 1] || DP[i - 1][j];
			}
			else{
				DP[i][j] = DP[i - 1][j - 1] && s[i] == p[j];
			}
		}
	}
	//DEBUG_2D(DP);
	return DP[s.size()-1][p.size()-1];
}


int main(){
	
	cout << isMatch("aabcd", "a?*") << endl; //1
	cout << isMatch("aab", "c*a*b") << endl; //0
	cout << isMatch("aa", "*") << endl; //1
	cout << isMatch("ef", "*") << endl; //1

	cout << isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl; //1
	cout << isMatch("aaac", "aaad") << endl; //0

	return 0;
}
