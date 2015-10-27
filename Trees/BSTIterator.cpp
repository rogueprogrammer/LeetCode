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
using namespace std;

//https://leetcode.com/problems/binary-search-tree-iterator/
//iterator returns the next smallest value in the BST

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class BSTIterator{
public:
	BSTIterator(TreeNode* root){
		TreeNode* cur = root;
		while (cur){
			st.push(cur);
			cur = cur->left;
		}
	}
	int next(){
		TreeNode* res = st.top();
		st.pop();
		TreeNode* cur = res;

		if (cur->right){
			st.push(cur->right);
			cur = cur->right;
			while (cur->left){
				st.push(cur->left);
				cur = cur->left;
			}
		}
		return res->val;
	}
	bool hasNext(){
		return !st.empty();
	}
private:
	stack<TreeNode*> st;
};



int main(){

	TreeNode* root = new TreeNode(10);
	TreeNode* b = new TreeNode(8); TreeNode* c = new TreeNode(13);
	root->left = b; root->right = c;

	TreeNode* d = new TreeNode(6); TreeNode* e = new TreeNode(9);
	b->left = d; b->right = e;

	TreeNode* f = new TreeNode(11); TreeNode* g = new TreeNode(14);
	c->left = f; c->right = g;

	BSTIterator i = BSTIterator(root);
	while (i.hasNext()){
		cout << i.next() << endl;
	}
	return 0;
}








