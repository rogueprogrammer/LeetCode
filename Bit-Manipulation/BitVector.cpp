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

void PrintBits(int x){
	for (int i = sizeof(x)*8-6; i >= 0; i--){
		bool res = (x & (1 << i));
		cout << i << " " << res << endl;
	}
}

//using constant space, and in alphabetical order without sorting the string, print all characters in a string
//idea: use a bit vector
void PrintAllAlphabetLetters(string str){
	int res = 0;
	for (int i = 0; i < str.size(); ++i){
		int posn = tolower(str[i]) - 'a';
		res = res | (1 << (26-posn));
	}
	//PrintBits(res);
	for (int i = sizeof(res)*8; i >= 0; --i){
		bool cur = res & (1 << i);
		if (cur){
			printf("%c", 'a' + (26-i));
		}
	}
}


int main(){

	PrintAllAlphabetLetters("this is a fked up qn");
	return 0;
}
