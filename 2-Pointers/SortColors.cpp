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
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

void sortColors(vector<int>& nums) {
	int lo = 0;
	int mid = 0;
	int hi = nums.size() - 1;
	
	while (mid < hi){
		switch (nums[mid]){
			case 0:
				swap(nums[lo++], nums[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(nums[hi--], nums[mid]);
				break;
		}
	}
#ifdef DEBUG_1D
	DEBUG_1D(nums);
#endif
}

int main(){
	vector<int> nums;
	nums = {0, 1, 2, 1, 2 };
	sortColors(nums);
	nums = { 0, 1, 2, 0, 0, 1, 0, 1, 2, 1, 2 };
	sortColors(nums);
	nums = { 1, 0 };
	sortColors(nums);
	nums = { 1, 2, 0, 0, 2, 1, 1, 0 };
	sortColors(nums);
	return 0;
}
