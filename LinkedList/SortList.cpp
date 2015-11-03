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

//https://leetcode.com/problems/sort-list/

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v) : val(v), next(NULL){}
};

//merge lists l1 and l2, given that they are either of length 1, or already in sorted order
ListNode* merge(ListNode* l1, ListNode* l2){
	ListNode* d = new ListNode(-1); //dummy
	ListNode* e = d;

	while (l1 && l2){

		if (l1->val <= l2->val){
			e->next = l1;
			l1 = l1->next;
		}
		else{
			e->next = l2;
			l2 = l2->next;
		}
		e = e->next;
	}
	while(l1){
		e->next = l1; 
		e = e->next;
		l1 = l1->next;
	}
	while(l2){
		e->next = l2;
		e = e->next;
		l2 = l2->next;
	}
	e->next = NULL;

	return d->next;
}


//apply merge sort to sort a linked list
ListNode* sortList(ListNode* head){
	if (!head || !head->next){
		return head;
	}

	//get middle node
	ListNode* s = head;
	ListNode* f = head->next;

	while (f && f->next){
		f = f->next;
		s = s->next;
	}
	ListNode* head2 = s->next;
	s->next = NULL;
	return merge(sortList(head), sortList(head2));
}


int main(){

	/*ListNode* a = new ListNode(5);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(6);
	b->next = a; a->next = c;

	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(7);
	ListNode* f = new ListNode(8);
	d->next = e; e->next = f;

	ListNode* res = merge(b, d);*/


	ListNode* a1 = new ListNode(21);
	ListNode* a = new ListNode(5);
	ListNode* b = new ListNode(2);
	ListNode* b1 = new ListNode(0);

	ListNode* c = new ListNode(6);
	a1->next = a;  a->next = b; b->next = b1; b1->next = c;
	ListNode* res = sortList(a1);

	return 0;
}
