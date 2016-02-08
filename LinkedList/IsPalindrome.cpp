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
//https://leetcode.com/problems/palindrome-linked-list/

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

 ListNode* ReverseList(ListNode* head){
	 ListNode* l1 = head;
	 ListNode* l2 = head->next;
	 ListNode* l3 = l2;

	 while (l2){
		 l3 = l3->next;
		 l2->next = l1;
		 l1 = l2;
		 l2 = l3;
	 }
	 head->next = NULL;
	 return l1;
 }

 bool isPalindrome(ListNode* head) {

	 //1. split the list into two halves:
	 ListNode* l1 = head;
	 ListNode* l2 = head;
	 int numNodes = 1;
	 while (l2 && l2->next){
		 l2 = l2->next->next;
		 l1 = l1->next;
		 numNodes += 2;
	 }
	 if (!l2){
		 --numNodes;
	 }
	
	 //2. Reverse the second half:
	 ListNode* reversed;
	 if (!numNodes % 2 == 0){ //if number of nodes is even, l1 is first element on the second half of the list
		 reversed = ReverseList(l1);
	 }
	 else{ //number of nodes is odd, l1->next is first element of the second half of the list
		 reversed = ReverseList(l1->next);
	 }

	 //3. Compare (Linked List from beginning and to (not including) Reverse, Linked List from Reverse to the very end). If not equal, return false

	 ListNode* temp1 = head;
	 ListNode* temp2 = reversed;
	 while( (temp1 != reversed) &&(temp2 != NULL)){
		 if (temp1->val != temp2->val) return false;
		 temp1 = temp1->next;
		 temp2 = temp2->next;
	 }
	 
	 return true;
 }


int main(){
	
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(3);
	ListNode* e = new ListNode(2);
	ListNode* f = new ListNode(1);
	//ListNode* g = new ListNode(1);
	a->next = b; 
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	//f->next = g;
	cout << isPalindrome(a) << endl;

	return 0;
}


