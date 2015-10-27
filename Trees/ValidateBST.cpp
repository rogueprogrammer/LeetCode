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

//https://leetcode.com/problems/validate-binary-search-tree/

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

bool isBST(TreeNode* root, int min, int max){
	if (!root){ 
		return true; 
	}
	if ((root->val > max) || (root->val < min)){
		return false;
	}
	if (root->left){
		if (root->left->val > root->val){
			return false;
		}
	}
	if (root->right){
		if (root->right->val < root->val){
			return false;
		}
	}
	return isBST(root->left, min, root->val) &&
		isBST(root->right, root->val, max);
}


bool isValidBST(TreeNode* root){
	return isBST(root, INT_MIN, INT_MAX);
}


int main(){

	TreeNode* root = new TreeNode(10);
	TreeNode* b = new TreeNode(8); TreeNode* c = new TreeNode(13);
	root->left = b; root->right = c;

	TreeNode* d = new TreeNode(6); TreeNode* e = new TreeNode(9);
	b->left = d; b->right = e;

	TreeNode* f = new TreeNode(5); TreeNode* g = new TreeNode(15);
	c->left = f; c->right = g;

	cout << isValidBST(root) << endl;
	return 0;
}








