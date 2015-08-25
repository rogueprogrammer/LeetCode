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

//Idea is to keep track of the most recent occurences of all letters in array (occurences)
//If we encounter the letter again, we take its previous occurence to update the last seen occurence (lastOccurence)
//Then we update the letters position in the occurences array. 
//let DP[i] = the longest substring without repeating character from last occurence to s[i]
//Therefore DP[i] = abs(i - lastOccurence) 
int largestSubstringWithoutRepeatingCharacters(string s){
	vector<int> occurences(26, -1);
	int lastOccurrence = -1;
	vector<int> DP(s.size());
	int max_res = INT_MIN;

	for (int i = 0; i < s.size(); ++i){
		char cur = s[i];
		int posn =  tolower(cur) - 'a' ;
		if (occurences[posn] != -1){ //already seen
			lastOccurrence = max(occurences[posn], lastOccurrence);
		}
		occurences[posn] = i;
		DP[i] = abs(i - lastOccurrence);
		max_res = max(DP[i], max_res);
	}
	//DEBUG_1D(DP);
	return max_res;

}



int main(){

	cout << largestSubstringWithoutRepeatingCharacters("pizzalasagnasamosapaprichaat") << endl; //aprich -> 6
	cout << largestSubstringWithoutRepeatingCharacters("dvdf") << endl; //vdf -> 3
	return 0;
}
