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

//https://leetcode.com/problems/compare-version-numbers/


int compareVersion(string version1, string version2){

	int dot1 = -1; int dot2 = -1;
	int len1 = version1.size();
	int len2 = version2.size();
	int cur1; int cur2;

	while (dot1 < len1 && dot2 < len2){
		int old1 = dot1; int old2 = dot2;
		dot1 = version1.find(".", dot1 + 1);
		dot2 = version2.find(".", dot2 + 1);
		if (dot1 < 0 || dot2 < 0){
			string str1 = version1.substr(old1 + 1, len1 - old1 - 1);
			string str2 = version2.substr(old2 + 1, len2 - old2 - 1);
			cur1 = stoi(str1, nullptr, 10); 
			cur2 = stoi(str2, nullptr, 10);
			if (cur1 > cur2) return 1;
			else if (cur2 > cur1) return -1;
			else break;
		}
		string str1 = version1.substr(old1+1, dot1 - old1 -1);
		string str2 = version2.substr(old2+1, dot2 - old2 -1);
		cur1 = stoi(str1, nullptr, 10);
		cur2 = stoi(str2, nullptr, 10);
		if (cur1 > cur2) return 1;
		else if (cur2 > cur1) return -1;
	}
	return 0; 
}


int main(){
	
	string version1 = "100.20.1";
	string version2 = "1.30.1";
	cout << compareVersion(version1, version2) << endl; //1
	cout << compareVersion("1001.200.2", "1001.201.2") << endl; //-1
	cout << compareVersion("1001.200.3", "1001.200.2") << endl; //1
	cout << compareVersion("1001.200.3", "1001.200.3") << endl; //0

	return 0;
}





