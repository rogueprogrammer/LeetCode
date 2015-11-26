#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_set>
#include <queue>
#include <map>
#include <list>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//https://leetcode.com/problems/invert-binary-tree/

TreeNode* invertTree(TreeNode* root){

	if (!root || (!root->left && !root->right)) return root;
	TreeNode* temp = root->right;
	root->right = root->left;
	root->left = temp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}
