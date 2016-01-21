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


bool BSearch(const vector<int>& A, int low, int hi, const int& input){

	int mid = (hi + low) / 2;
	if (A[mid] == input) return true;
	if (mid == low || mid == hi) return false;
	if ((A[mid] > A[mid - 1]) && (A[mid] < A[mid+1])){
		if (A[mid] > input){
			BSearch(A, low, mid - 1, input);
		}
		else{
			BSearch(A, mid + 1, hi,input);
		}
	}
	else if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]){ //rotate point
		if (input >= A[mid + 1] && input <= A[hi]){
			BSearch(A, mid + 1, hi, input);
		}
		else if (input >= A[low] && input <= A[mid - 1]){
			BSearch(A, low, mid - 1, input);
		}
		else{
			return false;
		}
	}
}


int main(){
	vector<int> A = {2,3,4,5,6,7,0,1};
	int input;
	//vector<int> A = { 4, 5, 6, 7, 0, 1, 2 };
	for(int i = 0 ; i < A.size(); ++i){ 
	  input = A[i];
	  cout << BSearch(A, 0, A.size() - 1, input);
	}
	input = 9;
	cout << BSearch(A, 0, A.size()-1, 9);
	return 0;
}
