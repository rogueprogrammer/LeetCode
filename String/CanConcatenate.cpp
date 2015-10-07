#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

/*
Given a vector of strings and another string (called conc), return whether or not conc can be formed by the concatenation of
other strings in the set. 

This approach forms all possible subsets from the given set, and then sees if conc can be formed
by the concatenation of the elements in the list of all possible subsets.

Better/simpler solution is to use backtracking. (see LeetCode/Backtracking/WordBreak.cpp for backtracking solution)

*/


bool IsAnagram(string str1, string str2){
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	return str1 == str2;
}

bool CanConcatenate(vector<string> strs, string conc){
	vector<vector<string>> table;
	set<string> res;

	for (int i = 0; i < strs.size(); ++i){
		if (i == 0){
			vector<string> first(1);
			first.push_back(strs[0]);
			table.push_back(first);
		}
		else{
			string cur_string = strs[i];
			int len = table.size();
			for (int j = 0; j < len; ++j){
				vector<string> prev = table[j];
				prev.push_back(cur_string);
				table.push_back(prev);
			}
			vector<string> single(1);
			single.push_back(cur_string);
			table.push_back(single);
		}
	}

	for (int i = 0; i < table.size(); ++i){
		vector<string> cur = table[i];
		string str;
		for (int j = 0; j < cur.size(); ++j){
			str += cur[j];
		}
		res.insert(str);
	}
	set<string>::iterator it = res.find(conc);
	if (it != res.end()){
		cout << "Can be concatenated from others in the set" << endl;
		return true;
	}
	else{
		for (it = res.begin(); it != res.end(); ++it){
			if (IsAnagram(*it, conc)){
				cout << "True - Can be concatenated from others in the set" << endl;
				return true;
			}
		}
		cout << "False - Can not be concatenated from others in the set" << endl;
	}

	return false;
}



int main(){

	vector<string> S = { "1", "2", "3", "46", "5" };
	CanConcatenate(S, "532"); //returns true as expected
	CanConcatenate(S, "46521"); //returns true as expected
	CanConcatenate(S, "465219"); //returns false as expected

	return 0;
}



