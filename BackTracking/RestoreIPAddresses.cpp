#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
//https://leetcode.com/problems/restore-ip-addresses/

void DFS(vector<string>& res, string in, int posn, string cur, int numDots){

	if (numDots > 4){
		return;
	}
	if (posn > in.size()) return;
	if (posn == in.size()){
		if (numDots == 4) {
			cur.pop_back();
			res.push_back(cur);
		}
		return;
	}
	string push = "";
	for (int len = 1; len <= 3; ++len){
		if (posn + len - 1 >= in.size()) continue;
		push += in[posn + len - 1];
		if (stoi(push) > 0 && stoi(push) <= 255){
			cur += push;
			cur += ".";
			DFS(res, in, posn + push.size(), cur, numDots + 1);
			for (int i = 0; i < push.size() + 1; ++i){
				cur.pop_back();
			}
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	string in;
	int posn = 0;
	string cur = "";
	int numDots = 0;
	DFS(res, s, posn, cur, numDots);
	return res;
}


int main(){
	string in = "25525511135";
	vector<string> res = restoreIpAddresses(in);
	return 0;
}
