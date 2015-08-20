#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;

//https://leetcode.com/problems/triangle/
//This problem can easily be done in O(n^2) space and time, where n = triangles.size()
//The real challenge is to get it in O(n) space, with O(n^2) time, which is what the below solution does:

int minimumTotal(vector<vector<int>>& triangle) {
	int num_rows = triangle.size();
	vector<int> res;

	for (int i = 0; i < num_rows; ++i){
		vector<int> temp(i + 1);
		for (int j = 0; j <= i; ++j){
			
			if (i == 0){
				temp[0] = triangle[0][0];
			}
			else if (i == 1){
				temp[0] = res[0] + triangle[1][0];
				temp[1] = res[0] + triangle[1][1];
			}
			else{

				if (j == 0){
					temp[j] = std::min(res[0], res[1]) + triangle[i][j];
				}
				else{
					int _min;
					if (i != j){
						 _min = res[j];
					}
					else{
						_min = res[j - 1];
					}
					if (j < res.size() - 1){ //get right
						_min = min(_min, res[j + 1]);
					}
					_min = min(_min, res[j - 1]);
					temp[j] = triangle[i][j] + _min;
				}
			}
		}
		res = temp;
		//DEBUG_1D(res);
	}
	int _min = res[0];
	for (int i = 1; i < res.size(); ++i){
		if (res[i] < _min) _min = res[i];
	}

	return _min;
}




int main(){

	vector<vector<int>> triangle = {
		{2},
		{3, 4},
		{6,5, 7},
		{4, 1, 8, 3}
	};

	cout << minimumTotal(triangle) << endl;
	return 0;
}

