#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <unordered_map>
#include <map>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include <cmath>
#include <set>
#include <unordered_set>
using namespace std;

int FindIndex(vector<int> & A){
	int low = 0; int hi = A.size();
	while (low <= hi){
		int mid = (low + hi) / 2;
		if (A[mid] > mid) hi = mid - 1;
		else if (A[mid] < mid) low = mid + 1;
		else return mid;
	}
	return -1;
}





int main(){


	vector<int> A = { 0, 1, 3, 4, 5, 6 };
	cout << FindIndex(A) << endl;
	
  return 0;	
}
