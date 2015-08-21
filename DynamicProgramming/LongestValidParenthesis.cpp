#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
using namespace std;

#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";}  cout << endl;

//https://leetcode.com/problems/longest-valid-parentheses/
//Idea is to maintain a stack of positions, where whatever position left on stack is the last unsatisfied bracket position
//Updating accumlator variable max_len based on current position and last unsatisfied bracket position whenever we see a satisfying pair
//This solution is purely stack-based, even tho the problem is flagged as DP. O(n) space and time

int longestValidParentheses(string str) {
	int max_len = 0;
	stack<int> s;
	s.push(-1); //empty position

	for (int i = 0; i < str.size(); ++i){
		int top = s.top(); 
		if (top == -1){
			s.push(i);
		}
		else if ((str[top] == '(') && (str[i] == ')')){
			s.pop();
			max_len = std::max(max_len, i - s.top());
		}
		else{
			s.push(i);
		}
	}

	return max_len;
}

int main(){

	cout << longestValidParentheses("(()()))(()()()()") << endl;
	cout << longestValidParentheses(")(())()") << endl;
	cout << longestValidParentheses(")(()()()())((()()()()()()()()()()()()") << endl;
	
	return 0;
}

