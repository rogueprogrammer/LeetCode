#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;
//https://leetcode.com/problems/decode-ways/
//O(n) algorithm to find number of ways to decode a string:
int numDecodings(string s){
	vector<int> DP(s.size()); //let DP[i] = number of decodings upto s[i]

	for (int i = 0; i < s.size(); ++i){
		if (i == 0){
			DP[i] = 1;
		}
		else{
			int prev = tolower(s[i - 1]) - '1';
			int cur = tolower(s[i]) - '1';
			if (prev <= 2 && cur <= 6){
				DP[i] = DP[i - 1] + 1;
			}
			else{
				DP[i] = DP[i - 1];
			}
		}
	}
	return DP[s.size() - 1];
}


int main(){
	cout << numDecodings("1247") << endl; //3
	cout << numDecodings("1234236") << endl; //6
	return 0;
}
