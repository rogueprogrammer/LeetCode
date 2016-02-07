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
#include <stack>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, int k, stack<TreeNode*> & st, int & n){
	if (root->left) inorder(root->left, k, st, n);
	st.push(root);
	++n;
	if (root->right) inorder(root->right, k, st, n);
}


int kthSmallest(TreeNode* root, int k) {
	stack<TreeNode*> st;
	int count = 0;
	inorder(root, k, st, count);
	int numNodesToPop = count - k;
	for (int i = 0; i < numNodesToPop; ++i){
		st.pop();
	}
	int res = st.top()->val;
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
	cout << kthSmallest(a, 3) << endl;

}
