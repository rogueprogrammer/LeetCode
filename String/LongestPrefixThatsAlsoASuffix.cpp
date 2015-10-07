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
// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
//idea - keep 2 pointers, and increment strategically.
//O(n) algorithm where n == str.size()

int longestPrefixThatsAlsoASuffix(string str){
	if (str.size() == 0) return 0;
	if (str.size() == 1) return 0;
	if (str.size() == 2) return str[0] == str[1];
	vector<int> phi(str.size());
	int longest = 0;
	phi[0] = 0;
	if (str[0] == str[1]) phi[1] = 1;
	else phi[1] = 0;
	int prev = 0; int cur = 2;
	for (; cur < str.size(); ++cur){
		if (str[prev] == str[cur]) { phi[cur] = phi[cur - 1] + 1; ++prev; }
		else{
			if (prev != 0 && str[cur] == str[prev - 1]){
				phi[cur] = phi[cur - 1];
			}
			else{
				phi[cur] = 0; prev = 0;
			}
		}
		longest = max(longest, phi[cur]);
	}
	//DEBUG_1D(phi);
	return longest;
}



int main(){
	
	cout << longestPrefixThatsAlsoASuffix("ababaca") << endl; //3
	cout << longestPrefixThatsAlsoASuffix("AABAACAABAA") << endl; //5
	cout << longestPrefixThatsAlsoASuffix("ABCDE") << endl; //0
	cout << longestPrefixThatsAlsoASuffix("AAAAA") << endl; //4
	cout << longestPrefixThatsAlsoASuffix("AAABAAA") << endl; //3
	cout << longestPrefixThatsAlsoASuffix("AAACAAAAAC") << endl; //4
	
	return 0;
}





