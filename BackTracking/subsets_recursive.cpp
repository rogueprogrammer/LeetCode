#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

//https://leetcode.com/problems/subsets/

vector<vector<int>> res;
void DFS(vector<int> & row, int posn, vector<int> & nums){

	if (posn >= nums.size()) {
		return;
	}
	row.push_back(nums[posn]);
	res.push_back(row);
	for (int i = posn+1; i < nums.size(); ++i){
		DFS(row, i, nums);
		row.pop_back();
	}

}

vector<vector<int>> subsets(vector<int>& nums){
	for (int i = 0; i < nums.size(); ++i){
		vector<int> row;
		DFS(row, i, nums);
	}
	return res;
}


void main(){
	vector<int> nums = { 1, 2, 3, 4 };
	subsets(nums);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
}
