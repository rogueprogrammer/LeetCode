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

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void Connect(TreeLinkNode* root){
	if (!root) return;
	if (root->left && root->right){
		root->left->next = root->right;
	}
	if (root->next && root->right){
		root->right->next = root->next->left;
	}
	Connect(root->left);
	Connect(root->right);
}
