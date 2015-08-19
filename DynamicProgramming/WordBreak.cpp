#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;
//https://leetcode.com/problems/word-break/
//This is a DP solution
//let DP[i] = true if word can be formed from s[j...i] where j = 0 initially and is updated to the next DP[i] that is 1


bool wordBreak(string s, unordered_set<string> & dict){
	vector<bool> DP(s.size()+1);
	DP[0] = 1;
	for (int i = 0; i < DP.size(); ++i){
		for (int j = 0; j <= i; ++j){
			if (DP[j]){
				string word = s.substr(j, i - j);
				if (dict.find(word) != dict.end()){
					DP[i] = 1;
				}
			}
		}
	}
	//DEBUG_1D(DP);
	return DP[s.size()];
}


int main(){

	unordered_set<string> dict = { "leet", "code", "leets" };
	cout << wordBreak("leet", dict) << endl;
	cout << wordBreak("leetz", dict) << endl;
	cout << wordBreak("leetscode", dict) << endl;
	cout << wordBreak("leetscodeleets", dict) << endl;
	cout << wordBreak("leetscodeleets", dict) << endl;
	cout << wordBreak("leetscodeleetsleetsleet", dict) << endl;
	cout << wordBreak("leetscodeleetsleetsleetss", dict) << endl;

	return 0;
}

