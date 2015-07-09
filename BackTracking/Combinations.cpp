#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

//https://leetcode.com/problems/combinations/
//RUNTIME IS: O(n-choose-k)
vector<vector<int>> res;

void DFS(int n, int k, int posn, int val, vector<int>& row){
	row.push_back(val);

	if (row.size() == k){
		res.push_back(row);
		for (int i = 0; i < row.size(); ++i) {
			cout << row[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = posn+1; i < k; ++i){
		for (int j = val + 1; j <= n; ++j){
			DFS(n, k, i, j, row);
			row.pop_back();
		}
	}
}

vector<vector<int>> combine(int n, int k){
	vector<vector<int>> res;
	vector<int> row; 
	for (int i = 1; i <= n; ++i){
		DFS(n, k, 0, i, row);
		res.push_back(row);
		row.pop_back();
	}
	return res;
}


int main(){
	combine(5, 3);
	combine(4, 2);
	combine(8, 5);
	return 0;
}
