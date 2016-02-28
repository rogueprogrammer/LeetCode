#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


/* Update input string with spaces, return all possible strings that can consume words by the dictionary
to consume the entire input string. */


unordered_set<string> dict = { "this", "is", "a", "word", "i", "saw", "cats", "cat", "and", "dog", "sand" };

/*
Idea:
Use backtracking/DFS.
For each word in the dictionary, check if the word can be formed from the current position 
(posn) in the input string. 
Do a depth first search to see if it can be formed with other words, 
adding posn += the size of the word that was previously
formed. Keep on maintaining the current string (cur) that can be formed from previous words in the dictionary.
Base case: If the accumulated position (posn) exceeds
the size of the inputted string, 
that means that all of the input string was used, and was able to be formed by the words
in the dictionary. This is key, we do not add words into our set of strings, unless consume the entire
input string with words from our dictionary.
Backtrack, in order to get all possible strings that can be formed with the dictionary words.
*/


void DFS(vector<string>& all, string s, int& posn, string& cur){

	if (posn >= s.size()){
		all.push_back(cur);
		return;
	}

	for (string curDictWord : dict){
		if (s.substr(posn, curDictWord.size()) == curDictWord){ //equivalent to bool isWord() function
			cur += curDictWord;
			cur += " ";
			posn += curDictWord.size();
			DFS(all, s, posn, cur);
			//Backtrack:
			cur = cur.substr(0, cur.size() - 1); //take out the last space
			cur = cur.substr(0, cur.size() - curDictWord.size());
			posn -= curDictWord.size();
		}

	}
}


vector<string> UpdateString(string strInput){

	vector<string>allPossibleUpdatedStrings;
	int posn = 0;
	string cur = "";
	DFS(allPossibleUpdatedStrings, strInput, posn, cur);
	for (string str : allPossibleUpdatedStrings){
		cout << str << endl;
	}
	return allPossibleUpdatedStrings;
}



int main(){
	UpdateString("catsanddog");
	UpdateString("thisisaword");

	return 0;
}
