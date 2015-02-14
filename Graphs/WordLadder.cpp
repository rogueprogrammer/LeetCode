#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <stack>
#include <unordered_set>
#include <queue>
using namespace std;

//https://oj.leetcode.com/problems/word-ladder/

bool OneCharDiff(const string& str1, const string& str2){
	if (str1.size() != str2.size()) return false;
	int diff = 0;
	for (int i = 0; i < str1.size(); ++i){
		if (str1[i] != str2[i]) ++diff;
	}
	return diff == 1;
}


int ladderLength(string start, string end, unordered_set<string>& dictionary){
	queue<string> q;
	unordered_set<string> unvisited;
	unvisited = dictionary;
	q.push(start);
	int level = 1;
	
	while (!q.empty()){
		string cur = q.front();
		if (OneCharDiff(cur, end)) return level;
		q.pop();
		unordered_set<string>::iterator itr = unvisited.begin();
		while (itr != unvisited.end()){
			string dict_word = *itr; 
			if (OneCharDiff((string&)*itr, cur)){ 
				q.push(*itr);
				itr = unvisited.erase(itr);
			}
			else{
				++itr;
			}	
		}
		++level;
	}
	return 0;
}



void main(){

	unordered_set<string> dictionary;
	dictionary.insert("hot");
	dictionary.insert("dot");
	dictionary.insert("dog");
	dictionary.insert("lot");
	dictionary.insert("log");

	for (const string& str : dictionary) cout << str << endl;

	cout << ladderLength("hit", "cog", dictionary);
	
}
