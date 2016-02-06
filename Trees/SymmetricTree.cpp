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
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

//https://leetcode.com/problems/symmetric-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetricUtil(TreeNode* c1, TreeNode* c2, bool & flagged){

	if (!c1 && !c2){
		return flagged;
	}

	if ((!c1 && c2) || (c1 && !c2)){
		flagged = false;
		return flagged;
	}
	if (c1->val != c2->val){
		flagged = false;
		return flagged;
	}

	return isSymmetricUtil(c1->left, c2->right, flagged) &&
		isSymmetricUtil(c1->right, c2->left, flagged);
}


bool isSymmetric(TreeNode* root) {
	if (!root) return true;
	TreeNode* c1 = root->left;
	TreeNode* c2 = root->right;
	if ((!c1 && c2) || (c1 && !c2)) return false;
	if (!c1 && !c2) return true;
	bool flagged = true;
	return isSymmetricUtil(c1, c2, flagged);
}
