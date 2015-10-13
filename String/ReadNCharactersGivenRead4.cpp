#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <math.h>
using namespace std;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;
typedef int int64;

/*
(locked leetcode qn)

The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. 
For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) 
that reads n characters from the file.

*/


int read4(char* buf){
	int numBytesRead = 0;
	return numBytesRead;
}


int read(char* buf, int n){
	int remainder = n % 4;
	int numTimes = n / 4;
	int bytesRead = 0;
	int cur = 0; 
	
	for (int i = 0; i < numTimes && cur != 0; ++i){
		cur = read4(buf); 
		bytesRead += cur;
		buf += 4;
	}
	
	if (remainder != 0 && cur != 0){
		bytesRead += read4(buf);
		buf += remainder;
	}
	return min(n, bytesRead); //needs to be min to cover the case of when n is larger than sizeof(buf)
}
