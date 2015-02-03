#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
using namespace std;

/*Strategy: Use 2 pointers, 1 at index 0, 1 at index size -1. Move the two pointers depending on if their sum
is less than or greater than target. */

bool sorted2Sum(vector<int>& v, int target){
	int i1 = 0;
	int i2 = v.size() - 1;
	while (i1 < i2){
		if (v[i1] + v[i2] == target) return true;
		else if (v[i1] + v[i2] > target) --i2;
		else if (v[i1] + v[i2] < target) ++i1;
	}
	return false;
}


void main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  v.push_back(7);
  v.push_back(9);
  v.push_back(11);
  v.push_back(13);
  cout << sorted2Sum(v, 18) << endl;
  cout << sorted2Sum(v, 118) << endl;
}
