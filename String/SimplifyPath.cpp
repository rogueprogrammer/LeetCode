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
#include <map>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

//https://leetcode.com/problems/simplify-path/
//Working solution (passed all test cases on OJ)

string simplifyPath(string path){
	string res;
	string buff;
	vector<string> stk;

	for (int i = 0; i < path.size(); ++i){
		if (path[i] == '/'){
			if (buff == "."){ buff = ""; }
			else if (buff == ".."){
				buff = "";
				if (!stk.empty()){
					stk.pop_back();
				}
				else{}
			}
			else{
				if (buff.size() > 0){ stk.push_back(buff); buff = "";}
			}
		}
		else{
			if (i != path.size() - 1){
				buff += path[i];
			}
			else{
				buff += path[i];
				if (buff == "."){ buff = ""; }
				else if (buff == ".."){ 
					buff = "";
					if (!stk.empty()){ 
						stk.pop_back(); 
					} 
				}
				else{
					if (buff.size() > 0){
						stk.push_back(buff); 
					}
				}
			}
		}
		
	}
	res += "/";
	for (int i = 0; i < stk.size(); ++i){ res += stk[i];  res += "/"; }
	if (res.size() > 1 && res.back() == '/') res.pop_back();

	return res;
}

int main(){

	string s;
	//string s = "..hidden";
	//string s = "/qSNIo///b/../BtIY/DrG/./MTWto/.///./h/../dz/KBIma/y/wgatd/fhrm///ePfTD/Hef/TVM/../mhZ/JR/.///";
	//string s = "/qSNIo///b/../BtIY/DrG/./MTWto/.///./h/../dz/KBIma/y/wgatd/fhrm///ePfTD/Hef/TVM/../mhZ/JR/.///vnZ/cRCQu";
	//string s = "/../";
	//string s = "/.hidden";
	//string s = "c/../..";
	s = "/...";
	s = "/a/./b/../../c/";
	s = "/home/../../..";
	cout << simplifyPath(s) << endl;;
	return 0;
}

