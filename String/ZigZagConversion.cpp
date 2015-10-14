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
//https://leetcode.com/problems/zigzag-conversion/

//O(numRows * s.size() ) algorithm 

string convert(string s, int numRows){

	vector<vector<char>> m(numRows, vector<char>(s.size()));
	for (int i = 0; i < numRows; ++i){
		for (int j = 0; j < s.size(); ++j){
			m[i][j] = ' ';
		}
	}
	bool vert = true; bool diag = false;
	int n_r = 0; int n_c = 0;
	m[n_r][n_c] = s[0];
	for (int i = 1; i < s.size(); ++i){
		if (i != 1 && (n_r+1 == numRows || n_r == 0)){
			if (vert){
				vert = false; diag = true;
			}
			else{
				vert = true; diag = false;
			}
		}
		if (vert){
			++n_r;
		}
		else{
			--n_r; ++n_c;
		}
		m[n_r][n_c] = s[i];
	}
	//DEBUG_2D(m);
	string res;

	for (int i = 0; i < numRows; ++i){
		for (int j = 0; j < s.size(); ++j){
			if (m[i][j] != ' '){
				res += m[i][j];
			}
		}
	}
	return res;
}

int main(){
	
	cout << convert("PAYPALISHIRING", 3) << endl;
	cout << convert("PAYPALISHIRING", 4) << endl;
	
	return 0;
}
