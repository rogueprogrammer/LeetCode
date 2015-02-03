#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> PlusOne(vector<int> digits){
	bool carry_over = false;
	for (int i = digits.size() - 1; i >= 0; --i){
		if (i == digits.size() - 1){
			if (digits[i] == 9){
				carry_over = true;
				digits[i] = 0;
			}
			else{
				++digits[i];
			}
		}
		else{
			if (digits[i] == 9){
				if (carry_over){
					digits[i] = 0;
				}
			}
			else{
				if (carry_over){
					++digits[i];
				}
				carry_over = false;
			}
		}
	}
	return digits;
}
