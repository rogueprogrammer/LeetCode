#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/regular-expression-matching/
// Let DP[i][j] = true if s[0..i] matches p[0..j], else = false

bool isMatch(string s, string p) {
	string X = " ";
	X += s;
	s = X;
	string Y = " ";
	Y += p;
	p = Y;

	vector<vector<bool>> DP(s.size() + 1, vector<bool>(p.size() + 1));
	DP[0][0] = 1;
	for (int i = 1; i < DP.size(); ++i){
		DP[i][0] = 0;
	}

	for (int i = 0; i < DP.size(); ++i){
		for (int j = 0; j < DP[0].size(); ++j){
			if (i == 0 && j == 0) {
				continue;
			}
			if (s[i] != p[j]){
				if (p[j] == '.') {
					DP[i][j] = 1;
				}
				if (p[j] != '*') {
					DP[i][j] = 0;
				}
				else{ //p[j] == '*'
					DP[i][j] = DP[i][j - 2] || p[j - 1] == s[i] || p[j-1] == '.'; //0 of previous char or 1 of previous char
				}
			}
			else{
				DP[i][j] = DP[i - 1][j - 1];
			}
		}
	}
	
	return DP[s.size()][p.size()];
}


int main(){
	bool res;
	
	res = isMatch("aa", ".*"); //→ true 
	res = isMatch("ab", ".*"); //→ true 
	res = isMatch("aa", "a"); //→ false
	res = isMatch("aa", "aa"); //→ true
	res = isMatch("aaa", "aa"); //→ false
	res = isMatch("aa", "a*"); //→ true
	
	res = isMatch("aab", "c*a*b"); //→ true
	return 0;
}
