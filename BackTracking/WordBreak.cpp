#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define DEBUG_VEC(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

//https://leetcode.com/problems/word-break/
//Note that this version solves it using DFS. The problem is flagged under DP, but it can also be solved using DFS

bool DFS(string s, vector<string> dict, int& s_posn, bool& flag){

	if (s_posn > s.size() - 1){ 
		flag = true; 
		return true;
	}

	for (int i = 0; i < dict.size(); ++i){
		string str_dict = dict[i];
		if (s.substr(s_posn, str_dict.size()) == str_dict){
			s_posn += str_dict.size();
			DFS(s, dict, s_posn, flag);
			s_posn -= str_dict.size();
		}
	}

	return flag;
}


bool wordBreak(string s, vector<string>& wordDict) {
	int posn = 0;
	bool flag = false;
	return DFS(s, wordDict, posn, flag);
}


int main(){

	vector<string> dict = {
		"leet", "code", "leets"
	};
	cout << wordBreak("leet", dict) << endl;
	cout << wordBreak("leetz", dict) << endl;
	cout << wordBreak("leetcode", dict) << endl;

	return 0;
}

