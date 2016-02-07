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
#include <queue>
#include <stack>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Do a level order traversal, reversing the level on alternate levels
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (!root) return res;
	bool reverse = false;
	queue<TreeNode*> temp;
	temp.push(root);
	while (!temp.empty()){
		int curLevelCount = temp.size();
		vector<int> curLevel ;
		while (curLevelCount--){
			TreeNode* fr = temp.front();
			if (fr->left){
				temp.push(fr->left);
			}
			if (fr->right){
				temp.push(fr->right);
			}
			temp.pop();
			curLevel.push_back(fr->val);
		}
		if (reverse){
			std::reverse(curLevel.begin(), curLevel.end());
		}
		res.push_back(curLevel);
		reverse = !reverse;
	}
	return res;
}


int main(){
	
	TreeNode* a = new TreeNode(5);
	TreeNode* b = new TreeNode(3);
	TreeNode* c = new TreeNode(8);
	TreeNode* d = new TreeNode(2);
	TreeNode* e = new TreeNode(7);
	TreeNode* f = new TreeNode(12);
	a->left = b; a->right = c;
	b->left = d; 
	c->left = e; c->right = f;
	zigzagLevelOrder(a);
}
