#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <Queue>
using namespace std;



//Rotate Array:
//Given an array of n elements, rotate it to the right by k steps
/*
Ex: n = 7, k = 3 and a = [1,2,3,4,5,6,7] => [5,6,7,1,2,3,4]
[7,1,2,3,4,5,6] k = 1
[6,7,1,2,3,4,5] k = 2
[5,6,7,1,2,3,4] k = 3
*/

void rotate(int nums[], int n, int k){

	for (int i = 0; i < k; ++i){
		int last = nums[0];
		for (int j = 1; j < n; ++j){
			if (j == n - 1){ //swap nums[0] and nums[j]
				int cur = nums[j];
				nums[0] = cur;
				nums[j] = last;
			}
			else{
				int cur = nums[j];
				nums[j] = last;
				last = cur;

			}
		}
	}

	for (int i = 0; i < n; ++i){
		cout << nums[i] << endl;
	}

}




//aaaaaabbbcc => a6b3c2
string text_compression(string str){
	string res = "";
	for (int i = 0; i < str.size(); ++i){
		char cur = str[i];
		int count = 1;
		for (int j = i + 1; j < str.size(); ++j){
			if (str[j] != cur) break;
			++count;
			i = j;
		}
		res += cur;
		char buffer[33];
		 _itoa_s(count, buffer, 10);
		 res += buffer;
	}
	return res;
}


//Anagrams - Given an array of strings, return all groups of strings that are anagrams
/*
O(n) complexity (time and space) -> Use a hash table to store sorted version of all strings in strs, mapping to
all the indices in strs that correspond to it
*/

vector<string> anagrams(vector<string> & strs){

	vector<string> res;
	unordered_map<string, vector<int>> ht;
	unordered_map<string, vector<int>>::iterator it;

	for (int i = 0; i < strs.size(); ++i){
		string cur = strs[i];
		string cur_string = cur;

		sort(cur.begin(), cur.end());
		it = ht.find(cur); //find the sorted string

		if (it != ht.end()){ //its in the hash table
			(it->second).push_back(i);
		}
		else{ //not in the hash table
			vector<int> x;
			x.push_back(i);
			ht.insert(make_pair(cur, x));
		}
	}
	for (auto x : ht){
		if (x.second.size() > 1){
			for (int i = 0; i < x.second.size(); ++i)
				res.push_back(strs[x.second[i]]);
		}
	}
	return res;
}




//Reverse words in string - Given an input string, reverse the string word by word

string Reverse_String(string str, int start, int end){
	int orig_start = start;
	int orig_end = end;
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		++start;
		--end;
	}
	int len = orig_end - orig_start + 1;
	string s = str.substr(orig_start, len);
	return str.substr(orig_start, orig_end-orig_start+1);
}



/*
Idea:
"the sky is blue" -> "blue is sky the"
"eulb si yks eht" (Reverse entire string)
"blue is sky the"(Reverse each word)
*/
string Reverse_Words_String(string str){
	string res;

	//Reverse entire string
	str = Reverse_String(str, 0, str.size() - 1);
	
	//Reverse each word
	string cur;
	int start = 0;
	int end = 0;
	for (int i = 0; i < str.size(); ++i){
		if ((str[i] != ' ') && (i != str.size()-1)) 
			++end;
		else{
			res += Reverse_String(str, start, end);
			res += " ";
			start = i + 1;
			end = start;
		}
	}
	
	return res;
}





//Merge 2 sorted linked lists
struct node{
	int val;
	node* next;
	node(int v) : val(v), next(NULL){}
};

void Print_Linked_List(node* head){
	while (head != NULL) { cout << head->val << " -> "; head = head->next; }
}

/*
1->3->5->7
2->4->6
*/
node* MergeTwoSortedLinkedLists(node* n1, node* n2){
	node* res;
	if (n1->val <= n2->val) {
		res = n1;
		n1 = n1->next;
	}
	else{
		res = n2;
		n2 = n2->next;
	}
	node* head = res;
	while (n1 && n2){
		if (n1->val <= n2->val) {
			res->next = n1;
			res = res->next;
			n1 = n1->next;
		}
		else{
			res->next = n2;
			res = res->next;
			n2 = n2->next;
		}
	}
	if (n1) res->next = n1;
	if (n2) res->next = n2;

	return head;
}

//TREES
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) : val(v), left(NULL), right(NULL){}
};


//Given a binary tree, find the maximum path sum


int MaxPathSum(TreeNode *root, int& maxPath) {
	if (!root) return 0;
	int l = MaxPathSum(root->left, maxPath);
	int r = MaxPathSum(root->right, maxPath);
	maxPath = max(maxPath, root->val + l);
	maxPath = max(maxPath, root->val + r);
	maxPath = max(maxPath, root->val+l+r);
	maxPath = max(maxPath, root->val);


	int retval = root->val;
	retval = max(retval, root->val + l);
	retval = max(retval, root->val + r);
	retval = max(retval, root->val + l+r);
	return retval;
}
int maxPathSum(TreeNode *root) {
	int maxPath = INT_MIN;
	MaxPathSum(root, maxPath);
	return maxPath;
}


//Root to leaf path
//Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
//such that adding up all the values along the path equals the given sum.
bool RootToLeafPathSum(TreeNode* root, int sum, int sumacc){

	if (sumacc == sum) return true;
	if (!root) return false;

	return RootToLeafPathSum(root->left, sum, sumacc + root->val) ||
		RootToLeafPathSum(root->left, sum, sumacc + root->val);
}







//Least common ancestor Binary Tree





//Preorder/Inorder Binary tree construction
/*
Given a preorder and inorder traversal, reconstruct the tree.
Preorder = {root, left, right}
Inorder = {left, Root, right}
*/
TreeNode* PreorderInorderBuild(vector<TreeNode*> preorder, vector<TreeNode*> inorder, int start, int end){

	if (start >= end-1) return NULL;
	if (start == end-1) return inorder[start];

	TreeNode* root = preorder[start];

	int root_posn = start;
	for (; root_posn < end; ++root_posn){
		if (inorder[root_posn] == root) break;
	}
	root->left = PreorderInorderBuild(preorder, inorder, start+1, root_posn - 1);
	root->right = PreorderInorderBuild(preorder, inorder, root_posn + 1, end);

	return root;

}


//Print Level order
void PrintLevelOrder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	cout << root->val << endl;
	TreeNode* end_level = new TreeNode(-1);
	q.push(end_level);
	while (!q.empty()){
		TreeNode* front = q.front();
		if (front == end_level && q.size() != 1){ q.push(end_level); cout << endl; }
		if (front->left){ q.push(front->left); cout << " " << front->left->val; }
		if (front->right){ q.push(front->right); cout << " " << front->right->val; }
		q.pop();
	}

}









//merge intervals












void main(){
	
	/*cout << text_compression("aaaaaabbbcc") << endl;

	vector<string> strs; strs.push_back("dog"); strs.push_back("god"); strs.push_back("apple");
	vector<string> res = anagrams(strs);
	for (int i = 0; i < res.size(); ++i) cout << res[i] <<"   " << endl;


	cout << Reverse_Words_String("the sky is blue") << endl;


	node* n1 = new node(1);
	node* n2 = new node(2);
	node* n3 = new node(3);
	node* n4 = new node(4);
	node* n5 = new node(5);
	node* n6 = new node(6);
	node* n7 = new node(7);

	n1->next = n3; n3->next = n5; n5->next = n7;
	n2->next = n4; n4->next = n6;

	node* res_n = new node(10);
	res_n = MergeTwoSortedLinkedLists(n1, n2);
	Print_Linked_List(res_n);
	*/


	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* tm10 = new TreeNode(-10);
	TreeNode* tm4 = new TreeNode(-4);
	TreeNode* tm3 = new TreeNode(-3);
	TreeNode* t6 = new TreeNode(6);
	TreeNode* t8 = new TreeNode(8);
	t1->left = t2; t1->right = t3;
	t2->left = tm10; t2->right = t6;
	t3->left = tm4; //t3->right = tm3;
	//tm4->left = t8;
	//PrintLevelOrder(t1);


	//cout << maxPathSum(t1) << endl;

	//cout << RootToLeafPathSum(t1, -7, 0) << endl;


	int nums[4] = { 7, 1, 2, 3 };
	//rotate(nums, 4, 2);

	//PREORDER/INORDER BUILD:

	TreeNode* h = new TreeNode(8);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* f = new TreeNode(1);
	TreeNode* e = new TreeNode(1);
	TreeNode* d = new TreeNode(1);
	TreeNode* a = new TreeNode(1);
	TreeNode* g = new TreeNode(1);
	TreeNode* i = new TreeNode(1);

	vector<TreeNode*> preorder;
	preorder.push_back(h);
	preorder.push_back(b);
	//preorder.push_back(f);
	//preorder.push_back(e);
	//preorder.push_back(a);
	preorder.push_back(c);
	//preorder.push_back(d);
	//preorder.push_back(g);
	//preorder.push_back(i);


	vector<TreeNode*> inorder;
	//inorder.push_back(f);
	inorder.push_back(b);
	//inorder.push_back(a);
	//inorder.push_back(e);
	inorder.push_back(h);
	inorder.push_back(c);
	//inorder.push_back(d);
	//inorder.push_back(i);
	//inorder.push_back(g);

	TreeNode* res_node = PreorderInorderBuild(preorder, inorder, 0, preorder.size());
	PrintLevelOrder(res_node);



	system("PAUSE");
}
