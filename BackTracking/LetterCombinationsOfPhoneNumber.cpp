#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

///// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
  vector<string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

  void dfs(string digits, int cur_dig, vector<string>& res, string str){
  	if (cur_dig == digits.size()){
  		res.push_back(str);
  		return;
  	}
  	int cur_ind = digits[cur_dig] - '0';
  	string cur_str = mapping[cur_ind];
  	for (int i = 0; i < cur_str.size(); ++i){
  		str += cur_str[i];
  		dfs(digits, cur_dig + 1, res, str);
  		str.pop_back();
  	}
  	
  }

  vector<string> letterCombinations(string digits){
  	vector<string> res;
  	if (digits == "") return res;
  	dfs(digits, 0, res, "");
  	return res;
  }
};
