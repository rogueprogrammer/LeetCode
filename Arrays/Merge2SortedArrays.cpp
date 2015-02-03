#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void merge(int A[], int m, int B[], int n){
	int cur = m + n - 1;
	for (int a = m - 1, b = n - 1; a >= 0 && b >= 0;){

		if (A[a] < B[b]){
			A[cur] = B[b];
			b--; cur--;
		}
		else{
			A[cur] = A[a]; 
			a--; cur--;
		}
	}

	for (int i = 0; i < m + n; ++i){
		cout << A[i] << endl;
	}
}
