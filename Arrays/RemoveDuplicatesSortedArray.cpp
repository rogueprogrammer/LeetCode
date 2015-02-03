#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int RemoveDuplicates(int A[], int n){
	int count = 1;
	for (int i = 1; i < n; ++i){
		int prev = A[i - 1];
		if (prev != A[i]) A[count++] = A[i];
	}
	for (int i = 0; i < n; ++i) cout << A[i] << endl;
	cout << endl;
	return count;
}
