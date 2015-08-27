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

//https://leetcode.com/problems/palindrome-partitioning/
/*
Ex - "aabcc", returns:
a, a, b, c, c
a, a, b, cc
aa, b, c, c
aa, b, cc
*/


bool IsPalindrome(string s){
	int first = 0; int last = s.size() - 1;
	while (last > first) if (s[last--] != s[first++]) return false;
	return true;
}

void DFS(string s, int curPos,  vector<vector<string>>& res, vector<string>& row){
	if (curPos >= s.size()){
		res.push_back(row);
		return;
	}

	for (int i = 1; i <= s.size() - curPos; ++i){
		string cur = s.substr(curPos, i);
		if (IsPalindrome(cur)){
			row.push_back(cur);
			curPos += i;
			DFS(s, curPos, res, row );
			curPos -= i;
			row.pop_back();
		}
	}
}


vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	vector<string> row;
	DFS(s, 0,  res, row);
	for (int i = 0; i < res.size(); ++i){
		int len = res[i].size();
		for (int j = 0; j < len; ++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return res;
}

int main(){
	partition("2002");
	cout << endl;
	partition("aabcc");
	cout << endl;
	partition("200101002");
	return 0;
}













