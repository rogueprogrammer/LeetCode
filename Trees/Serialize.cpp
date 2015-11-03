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
using namespace std;

//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


string serialize(TreeNode* root) {
	string str = "";
	if (!root){
		str += "null";
		return str;
	}
	//use a queue to do a Breadth-first traversal of the tree
	queue<TreeNode*> q;
	q.push(root);
	bool first = true; //first node
	while (!q.empty()){
		TreeNode* cur = q.front();
		q.pop();
		if (cur->val == -1){ 
			str += ",null"; 
		}
		else {
			if (!first){
				str += ",";
			}
			str += to_string(cur->val);
			first = false;
		}
		if (cur->left){ 
			q.push(cur->left); 
		}
		else {
			if (cur->val != -1){
				q.push(new TreeNode(-1));
			}
		}
		if (cur->right){
			q.push(cur->right);
		}
		else {
			if (cur->val != -1){
				q.push(new TreeNode(-1));
			}
		}
	}
	int i = str.size() - 5;
	while (str.substr(i, 5) == ",null"){ //get rid of all the last ",NULL"s
		str.erase(i, 5);
		i -= 5;
	}
	return str;
}


int main(){

	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(4);
	TreeNode* e = new TreeNode(5);
	TreeNode* f = new TreeNode(6);
	TreeNode* g = new TreeNode(7);

	a->left = b; a->right = c;
	c->left = d; c->right = e; e->right = f;
	string res = "";
	res = serialize(a);
	cout << res << endl;

	string serial = "1,2,3,null,null,4,5";
	return 0;
}



