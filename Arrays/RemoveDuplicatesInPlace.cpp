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

vector<int> RemoveDuplicatesInPlace(vector<int> a){
	sort(a.begin(), a.end()); //O(nlogn)
	int p = 0;
	int c = 1;
	while (c < a.size()){
		while (a[p] == a[c]){
			++c;
		}
		a[p+1] = a[c++];
		++p;
	}

	while (p < a.size()-1){
		a.pop_back();
	}
	DEBUG_1D(a);
	return a;
}

int main(){
	//vector<int> a = { 1, 1, 3, 3, 3, 5 };
	vector<int> a = { 6, 7, 1, 3, 4, 2, 3, 2, 6, 9 }; 	//{ 1, 2, 2, 3, 3, 4, 6, 6, 7, 9 };

	RemoveDuplicatesInPlace(a);
	return 0;
}

