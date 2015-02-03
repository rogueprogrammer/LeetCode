#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*https://oj.leetcode.com/problems/remove-element/
Remove all instances of a certain value in an array

*/
void main(){
  int A[4] = { 1, 2, 3, 2 };
  int n = 4;
  int elem = 2;
  
  int count = 0;
  for (int i = 0; i < n; ++i){
    if (A[i] != elem) A[count++] = A[i];
  }
  for (int i = 0; i < n; ++i) cout << A[i] << endl;
}
