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
//I used a queue/BFT approach to serialize and deserialize the binary tree.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

string serialize(TreeNode* root) {
	if (!root) return "null";
	string res;

	queue<TreeNode*> q;
	q.push(root);


	while (!q.empty()){
		TreeNode* cur = q.front();
		q.pop();
		if (cur){
			q.push(cur->left);
			q.push(cur->right);
			res += to_string(cur->val);
		}
		else{
			res += "null";
		}
		res += ",";
	}
	int i = res.size() - 5;
	string str = res.substr(i, 5);
	while (res.substr(i, 5) == "null,"){
		res.erase(i, 5);
		i -= 5;
	}
	if (res.back() == ',') res.pop_back();

	return res;
}

int GetNextVal(string& str){
	int comma = str.find(',');
	if (comma == -1){ //last number in the string left
		int res = stoi(str);
		str = "";
		return res;
	}
	int val = stoi(str.substr(0, comma));
	str = str.substr(comma + 1);
	return val;
}


TreeNode* Deserialize(string data){
	if (data == "" || data == "#") return NULL;

	queue<TreeNode*> q;
	q.push(new TreeNode(GetNextVal(data)));
	TreeNode* res = q.front();

	while (!q.empty()){
		TreeNode* cur = q.front();
		if (!cur){
			q.pop();
			continue;
		}
		q.pop();
		
		TreeNode* left = NULL, *right = NULL;
		if (data == "") continue;
		if (data[0] == '#') {
			left = NULL;
			data = data.substr(2);
		}
		else{
			if(data != "") left = new TreeNode(GetNextVal(data));
		}
		if (data[0] == '#'){
			right = NULL;
			data = data.substr(2);
		}
		else{
			if (data != "")right = new TreeNode(GetNextVal(data));
		}
		if (cur != NULL){
			cur->left = left; 
			cur->right = right;
		}
		if (left) q.push(left);
		if (right) q.push(right);
	}
	return res;
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
	TreeNode* res = Deserialize(serial);
	cout << serialize(res) << endl; //should equal serial
	return 0;
}

