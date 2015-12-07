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

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : val(v), left(NULL), right(NULL){}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if (!root || !p || !q) return NULL;
	if (root == p || root == q) return root;
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if (left && right) return root; //both left and right subtrees have found p and q, return this root
	//if left subtree found p, return left, which will bubble upwards in this dfs function.
	//if its not in the left subtree, then it must be in the right subtree
	return left ? left : right; 
}


