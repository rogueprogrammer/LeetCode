#include "Header.h"

/*
Partition: Partitions all elements less than pivot (last element) to the left of it. Returns the ultimate position
in which pivot belongs. So if pivot is ultimately placed at position k, it is the (k+1)st smallest element.

A={5,2,6,9,4} first_hi = 0, i = 0, pivot = 4
{2, 5, 6, 9, 4} first_hi = 1, i = 1
{2, 4, 6, 9, 5} first_hi = 1, i = 4
*/

int Partition(vector<int>& A, int low, int hi){
	int pivot = A[hi];
	int first_hi = low; //first element greater than pivot
	
	for (int i = low; i < hi; ++i){
		if (A[i] < pivot) iter_swap(A.begin() + (first_hi++), A.begin() + i);
	}
	iter_swap(A.begin() + first_hi, A.begin() + hi);

	return first_hi;
}


//Selects k smallest element in O(n) time
int QuickSelectUtil(vector<int>& A, int k, int low, int hi){
	if (low >= hi){
		return -1; //not found
	}
	int p = Partition(A, low, hi);
	if (p == k){
		return A[k];
	}
	if (p > k){
		return QuickSelectUtil(A, k, low, p - 1);
	}
	else{
		return QuickSelectUtil(A, k, p + 1, hi);
	}
}


int QuickSelect(vector<int>& A, int k){
	return QuickSelectUtil(A, k-1 , 0, A.size()-1);
}

void QuickSort(vector<int>& A, int low, int hi){
	if (low < hi){
		int p = Partition(A, low, hi);
		QuickSort(A, low, p - 1);
		QuickSort(A, p + 1, hi);
	}
}



void main(){

	vector<int> A = { 5, 2, 6, 9, 4 };
	//cout << Partition(A, 0, A.size() - 1) << endl;
	//cout << QuickSelect(A, 2) << endl;
	//cout << QuickSelect(A, 3) << endl;
	QuickSort(A, 0, A.size()-1);
	for (int i = 0; i < A.size(); ++i){
		cout << A[i] << endl;
	}

}
