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
//https://leetcode.com/problems/implement-strstr/

//This is an implementation of strstr() using KMP's O(n) algorithm for finding pattern of length m in a string containing
//larger amount of text of length n.
//Idea of KMP:
//Preprocess the pattern string by computing the longest prefix thats also a suffix for each position i.
//Call this preprocess array to be phi
//Comparing the text and pat strings if txt[t] and pat[p] have a mismatch, we don't need to decrement p back to 0 necessarily
//Use phi[p-1] to see the largest prefix (also a suffix) of already matched characters, and adjust p to be phi[p-1]

vector<int> longestPrefixThatsAlsoASuffix(string str){
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
	return phi;
}

int KMP(string txt, string pat){
	vector<int> phi = longestPrefixThatsAlsoASuffix(pat);
	int t = 0; 
	int p = 0; 
	while (t < txt.size()){
		if (p == pat.size()){
			return t - p + 1;
		}
		if (txt[t] == pat[p]){
			++t; ++p;
		}
		else{
			if (p != 0){
				p = phi[p - 1];
			}
			else{
				++p; ++t;
			}
		}
	}
	if (p == pat.size()){
		return t - pat.size();
	}
	return -1;
}

int strStr(string haystack, string needle) {
  return KMP(haystack, needle);       
}

int main(){
	string txt = "abcxabcdabxabcdabcdabcy"; //15
	//string txt = "abcdabcdabcy"; //4
	string pat = "abcdabcy";
	cout << strStr(txt, pat) << endl;
	return 0;
}
