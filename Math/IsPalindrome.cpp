#include "header.h"


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
