#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <unordered_map>
#include <map>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include <cmath>
#include <set>
#include <unordered_set>
using namespace std;


bool IsPalindrome(int x){
	int n = x;
	int reversed = 0;
	while (x > 0){
		int digit = x % 10;
		reversed = (reversed * 10) + digit;
		x /= 10;
	}
	return reversed == n;
}
