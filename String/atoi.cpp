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

//https://leetcode.com/problems/string-to-integer-atoi/

int myAtoi(string str) {
	int len = str.size();
	int res = 0;
	int i = 0;
	bool is_negative = false;

	while (str[i] == ' ') ++i;
	if (str[i] == '-' || str[i] == '+'){
		if (str[i] == '-') is_negative = true;
		++i;
	}

	for (; i < len; ++i){
		if (str[i] > '9' || str[i] < '0') return 0; //handles case of when non-numeric characters are involved
		int cur = str[i] - '0';
		res += cur * pow(10, len - i - 1);
	}
	if (is_negative) res *= -1;
	
	return res;
}
