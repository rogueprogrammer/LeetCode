#include <iostream>
#include <string>
using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Idea:
Maintain an array, LastSeenIndex for each character in the string. Initialize it to be -1 (to mark that the char has not been seen)
Then update it for each char in the string, marking the index in the string for that char
If at any time, we have LastSeenIndex[c] != -1 (seen before) AND the LastSeenIndex[c] >= start (meaning that it has been seen 
after the start of the current longest substring), then we have a character that is repeated in the current longest substring and 
a new substring needs to be created => update start = lastSeenIndex[c] + 1 and maxLen
*/
int lengthOfLongestSubstring(string s){

	int lastSeenIndex[128];
	memset(lastSeenIndex, -1, sizeof(lastSeenIndex));
	int maxLen = 0;
	int start = 0;
	int i = 0;
	for (; i < s.size(); ++i){
		char c = s[i];
		if (lastSeenIndex[c] != -1 && lastSeenIndex[c] >= start){ //repeating character
			maxLen = max(maxLen, (i - 1) - start + 1);
			start = lastSeenIndex[c] + 1;
		}
		lastSeenIndex[c] = i;
	}
	maxLen = max(maxLen, i - start );
	return maxLen;
}

int main(){
	cout << lengthOfLongestSubstring("abcb") << endl; //3
	cout << lengthOfLongestSubstring("abbacdefgh") << endl; //8
	cout << lengthOfLongestSubstring("bbbbb") << endl; //1
	cout << lengthOfLongestSubstring("abcbdeafgh") << endl; //8
	cout << lengthOfLongestSubstring("bdb") << endl; //2


	return 0;
}
