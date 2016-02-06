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
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
//https://leetcode.com/problems/path-sum/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool hasPathSumUtil(TreeNode* root, int sum, int sumAcc, bool &flagged){
	if (!root){
		return flagged;
	}
	sumAcc += root->val;

	if (sumAcc == sum) {
		if (!root->left && !root->right){
			flagged = true;
			return flagged;
		}
	}
	return hasPathSumUtil(root->left, sum, sumAcc, flagged) ||
		hasPathSumUtil(root->right, sum, sumAcc, flagged);
}



bool hasPathSum(TreeNode* root, int sum) {
	if (!root) return false;
	int sumAcc = 0;
	bool flagged = false;
	return hasPathSumUtil(root, sum, sumAcc, flagged);
}


int main(){
	
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(-2);
	TreeNode* c = new TreeNode(-3);
	TreeNode* d = new TreeNode(1);
	TreeNode* e = new TreeNode(3);
	TreeNode* f = new TreeNode(-2);
	TreeNode* g = new TreeNode(-1);
	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f;
	d->left = g;
	cout << hasPathSum(a, -1) << endl;
	return 0;
}
