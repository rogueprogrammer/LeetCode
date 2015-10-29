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

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
//not working, get back to this qn:
//{2,1,3,0,7,9,1,2,#,1,0,#,#,8,8,#,#,#,#,7}
//{0,2,4,1,#,3,-1,5,1,#,6,#,8}

struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};



TreeLinkNode* FindNextChild(TreeLinkNode* root){
	if (!root || !root->next) return NULL;
	if (root->next){
		if (root->next->left) return root->next->left;
		if (root->next->right) return root->next->right;
		else FindNextChild(root->next);
	}
}

void connect(TreeLinkNode* root){

	TreeLinkNode* cur = root;
	while (cur){
		if (cur->left){
			if (cur->right){
				cur->left->next = cur->right;
			}
			else{
				cur->left->next = FindNextChild(cur);
			}
		}
		if (cur->right){
			cur->right->next = FindNextChild(cur);
		}
		if (cur->next) cur = cur->next;
		if (cur->left) cur = cur->left;
		if (cur->right) cur = cur->right;
		else break;
	}
}




int main(){



	/*TreeLinkNode* a = new TreeLinkNode(2); 
	TreeLinkNode* b = new TreeLinkNode(1);
	TreeLinkNode* c = new TreeLinkNode(3);
	TreeLinkNode* d = new TreeLinkNode(0);
	TreeLinkNode* e = new TreeLinkNode(7);
	TreeLinkNode* f = new TreeLinkNode(9);
	TreeLinkNode* g = new TreeLinkNode(1);
	TreeLinkNode* h = new TreeLinkNode(2);
	TreeLinkNode* i = new TreeLinkNode(1);
	TreeLinkNode* j = new TreeLinkNode(0);
	TreeLinkNode* k = new TreeLinkNode(8);
	TreeLinkNode* l = new TreeLinkNode(8);
	TreeLinkNode* m = new TreeLinkNode(7);
	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	d->left = h; 
	e->right = i;
	f->left = j;
	g->right = k;
	h->left = l;
	j->right = m;*/
	TreeLinkNode* a = new TreeLinkNode(1);
	TreeLinkNode* b = new TreeLinkNode(2);
	TreeLinkNode* c = new TreeLinkNode(3);
	TreeLinkNode* d = new TreeLinkNode(4);
	TreeLinkNode* e = new TreeLinkNode(5);
	a->left = b; a->right = c;
	b->left = d; b->right = e;
	connect(a);
	return 0;
}

/* This recursive solution won't work, as an iterative BFT is required.

void connect(TreeLinkNode* root){
	if (!root){
		return;
	}
	
	TreeLinkNode* cur = root;

	if (cur->left){
		if (cur->right){
			cur->left->next = cur->right;
		}
		else{
			cur->left->next = FindNextChild(cur);
		}
	}
	if (cur->right){
		cur->right->next = FindNextChild(cur);
	}
	
	Connect(root->left);
	Connect(root->right);
}
*/






