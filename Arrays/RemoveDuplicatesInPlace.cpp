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

vector<int> RemoveDuplicatesInPlace(vector<int> a){
	sort(a.begin(), a.end());
	int p = 0;
	int c = 1;
	while (c < a.size()){
		while (a[p] == a[c]){
			++c;
		}
		a[p + 1] = a[c++];
		++p;
	}

	while (p < a.size() - 1){
		a.pop_back();
	}

#ifdef DEBUG_1D
	DEBUG_1D(a);
#endif
	return a;
}


int main(){

	vector<int> nums;
	nums = {1, 3, 3, 3, 5, 6, 6, 7};

	RemoveDuplicatesInPlace(nums);
	return 0;
}
