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


//Given a string representing a number, add "," between every thousand
//eg - "1000" -> "1,000"
string addComma(string num){
	string res = "";
	int count = 0;
	for (int i = num.size(); i >= 0; --i, ++count){
		res.insert(res.begin(), num[i]);
		if (count == 3){
			char comma = ',';
			res.insert(res.begin(), comma);
			count = 0;
		}
	}
	return res;
}


int main(){
	cout << addComma("1000000") << endl;

	return 0;
}

