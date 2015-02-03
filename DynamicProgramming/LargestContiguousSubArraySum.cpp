#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;



int LargestContiguousSumSubarray(int a[], int size){
	int max_so_far = a[0];
	int cur_max = a[0];
	for (int i = 1; i < size; ++i){
		cur_max = max(a[i], cur_max + a[i]);
		max_so_far = max(max_so_far, cur_max);
	}
	return max_so_far;
}
