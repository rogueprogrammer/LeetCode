#include <iostream>
#include <string>


//https://leetcode.com/problems/excel-sheet-column-number/

int titleToNumber(string A) {
  int res = 0;
  
  for(int i = 0; i < A.size(); ++i){
      char cur = A[i];
      int place = A.size()-1 - i;
      int diff = cur - 'A';
      res += (pow(26, place) * ( diff + 1));
  }
  return res;
}
