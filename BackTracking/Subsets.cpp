#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//// https://leetcode.com/problems/subsets/
//Given a set of numbers, find all possible subsets

/*
[1] => {1}
[1, 2] => {1} + {1,2} + {2}

*/

vector<vector<int>> subsets(vector<int> &S){
	vector<vector<int>> res;
	sort(S.begin(), S.end());
	for (int i = 0; i < S.size(); ++i){
		if (i == 0){
			vector<int> temp(i + 1);
			temp.push_back(S[0]);
			res.push_back(temp);
		}
		else if (i > 0){
			int cur_i = res.size();
			for (int j = 0; j < cur_i; ++j){
				vector<int> prev = res[j];
				prev.push_back(S[i]);
				res.push_back(prev);
			}
			vector<int> single(1);
			single.push_back(S[i]);
			res.push_back(single);
		}
	}
	return res;
}




int main(){

	vector<int> S = { 1, 2, 3,4, 5};
	vector<vector<int>> res = subsets(S);
	//cout << res.size() << endl; //equal to 2^n - 1, where n equals the length of the set S
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j){
			if (res[i][j] == 0){ continue; }
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
