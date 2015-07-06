#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
/* 
Given an ordered string, find the set of ordered indices of all permutations of the string that equal the orginal string.
Ex:
For "ABAB" -> 0123, 2301, 0321, 2103}
*/

set<vector<int>> AllOrderings(string str){

	set<vector<int>> res;
	vector<int> first;
	for (int i = 0; i < str.size(); ++i){first.push_back(i);}
	res.insert(first);

	for (int i = 0; i < str.size(); ++i){
		for (int j = 0; j < str.size(); ++j){
			if (i == j) continue;
			if (str[i] == str[j]){
				int len = res.size();
				auto it = res.begin();
				for (int k = 0; k < len; ++k, it++){
					vector<int> cur = *it;
					swap(cur[i], cur[j]);
					res.insert(cur);
				}
			}
		}
	}

	return res;
}

int main(){
	string str = "ABAB";
	set<vector<int>> res = AllOrderings(str);
	auto it = res.begin();
	for (int i = 0; i < res.size(); ++i, it++){
		vector<int> cur = *it;
		for (int j = 0; j < cur.size(); ++j){
			cout << cur[j] << " ";
		}
		cout << endl;
	}
}
