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
#include <queue>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

//https://leetcode.com/problems/path-sum-ii/
//Finds all root to leaf paths equal to sum

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};



void DFS(TreeNode* root, int sumAcc, int target, vector<vector<int>>& res, vector<int> cur){
	if (!root) return;
	if (!root->left && !root->right){
		sumAcc += root->val;
		if (sumAcc == target){
			cur.push_back(root->val);
			res.push_back(cur);
		}
		return;
	}

	cur.push_back(root->val);
	DFS(root->left, sumAcc + root->val, target, res, cur);
	DFS(root->right, sumAcc + root->val, target, res, cur);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
  int sumAcc = 0;
	vector<int> cur;
	vector<vector<int>> res;
	DFS(a, sumAcc, sum, res, cur);
	return res;
}

int main(){

	TreeNode* a = new TreeNode(2);
	TreeNode* b = new TreeNode(7);
	TreeNode* c = new TreeNode(6);
	TreeNode* d = new TreeNode(3);
	TreeNode* e = new TreeNode(4);
	TreeNode* f = new TreeNode(5);
	TreeNode* g = new TreeNode(-1);
	TreeNode* h = new TreeNode(18);

	a->left = b; a->right = c;
	b->right = d;
	c->left = e;
	c->right = f;
	f->left = g;
	b->left = h;
	int sumAcc = 0;
	vector<int> cur;
	vector<vector<int>> res;
	int target = 12;
  pathSum(a, target);

	return 0;
}
