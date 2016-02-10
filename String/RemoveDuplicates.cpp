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
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
//https://leetcode.com/problems/remove-duplicate-letters/

string removeDuplicateLetters(string s){
	vector<int> hash(256);
	int res = 0;
	for (int i = 0; i < s.size(); ++i){
		char cur = tolower(s[i]);
		int posn = cur - 'a';
		if (hash[posn] == 0){
			hash[posn] = 1;
			s[res++] = s[i];
		}
	}
	s.erase(res, s.size() - res + 1);
	return s;
}

int main(){
	cout << RemoveDuplicates("creamcheesebagel") << endl;
	return 0;
}
