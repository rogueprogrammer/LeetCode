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
typedef int int64;

//https://leetcode.com/problems/interleaving-string/
//This problem is flagged as DP, but I solved it using backtracking/dfs because of simplicity

bool dfs(string s1, string s2, string s3, int ps1, int ps2, int ps3, bool& flag){
	if (ps1 == s1.size() && ps2 == s2.size() && ps3 == s3.size()){
		flag = true;
		return true;
	}

	if (s3[ps3] == s1[ps1]){
		++ps1; ++ps3;
		dfs(s1, s2, s3, ps1, ps2, ps3, flag);
		--ps1; --ps3;
	}
	if (s3[ps3] == s2[ps2]){
		++ps2; ++ps3;
		dfs(s1, s2, s3, ps1, ps2, ps3, flag);
		--ps2; --ps3;
	}
	return flag;

}

bool isInterleave(string s1, string s2, string s3) {
	bool flag = false;
	return dfs(s1, s2, s3, 0, 0, 0, flag);
}

int main(){
	
	string s1 = "aabcc";
	string s2 = "dbbca";
	//string s3 = "aadbbcbcac"; //true
	string s3 = "aadbbbaccc"; //false
	cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl; //true
	cout << isInterleave(s1, s2, s3) << endl; //false
	return 0;
}
