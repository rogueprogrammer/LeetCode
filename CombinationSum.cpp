#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/combination-sum/
//Problem with my solution is that it includes all permutations of all the combinations.
//To fix this, just use a set to include unique vector of integers. <- DOESNT WORK.  USE DYNAMIC PROGRAMMING SOLUTION INSTEAD


set<vector<int>> res2;
void DFS2(vector<int> nums, int target, vector<int>& row, int& sumAcc){
	if (sumAcc == target){
		
		auto it =res2.find(row);
		if (it == res2.end()){ //
			res2.insert(row);
			for (int i = 0; i < row.size(); ++i){
				cout << row[i] << " ";
			}
			cout << endl;
		}
		//res2.push_back(row);
		return;
	}

	for (int i = 0; i < nums.size(); ++i){
		int cur = nums[i];
		if (cur + sumAcc <= target){
			row.push_back(cur);
			sumAcc += cur;
			DFS2(nums, target, row, sumAcc);
			sumAcc -= cur;
			row.pop_back();
		}
		else{
			break;
		}
	}
}





int main(){

	vector<int> nums = { 2, 3, 6, 7 };
	int target = 13;
	vector<int> row;
	int sumAcc = 0;
	sort(nums.begin(), nums.end());
	DFS2(nums,  target, row, sumAcc);
	
	return 0;
}
