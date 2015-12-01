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

//My very own implementation of a (key, value) hash table, with (on average) logarithmic access time
//Since I did not implement a self-balancing tree such as AVL or Redblack tree, but rather just a BST, at worst-case the access time is linear
//This would occur if all the inserted keys hashed to the same position, and are inserted in either ascending or descending order.
//Hopefully such a rare case does not occur...

struct TreeNode{
	int key;
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int k = -1) : key(k), left(NULL), right(NULL){} //a TreeNode with -1 as the key denotes an "empty" node
	TreeNode(int k, int v) : key(k), val(v), left(new TreeNode(-1)), right(new TreeNode(-1)){}
};

class HT {

public:
	HT(int size = 13) : len(size){
		for (int i = 0; i < len; ++i){
			table.push_back(new TreeNode());
		}
	}

	void insert(int k, int v){
		int pos = k % len;
		if (table[pos]->key == -1){
			table[pos]->key = k;
			table[pos]->val = v;
		}
		else{
			TreeNode* cur = table[pos];
			while (1){
				if (k < cur->key){
					if (!cur->left){
						cur->left = new TreeNode(k, v);
						break;
					}
					else{
						cur = cur->left;
					}
				}
				else{
					if (!cur->right){
						cur->right = new TreeNode(k, v);
						break;
					}
					else{
						cur = cur->right;
					}
				}
			}
		}
	}

	void PrintContents(){
		for (int i = 0; i < len; ++i){
			TreeNode* cur = table[i];
			if (cur->key != -1){
				cout << "Hash "<<  i << " : " << endl;
				DFS(cur);
			}
		}
	}

	int Get(int key){
		int posn = key % len;
		TreeNode* cur = table[posn];
		while (1){
			if (!cur) return -1;
			else if (cur->key == key) return cur->val;
			else if (cur->key == -1) return -1;
			else{
				if (cur->key > key) cur = cur->left;
				else cur = cur->right;
			}
		}
	}

protected:
	void DFS(TreeNode* root){
		if (!root || root->key == -1) return;
		cout << "    Key: " << root->key << "Val: " << root->val << endl;
		DFS(root->left);
		DFS(root->right);
	}

private:
	vector<TreeNode*> table;
	int len;

};

