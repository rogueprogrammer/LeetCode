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
#include <map>
#include <queue>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}

//https://leetcode.com/problems/add-two-numbers/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode result(-1);

	ListNode* cur = &result;
	bool carry = false;
	while (l1 || l2 || carry){
		if (!l1 && !l2){ //carry the 1
			cur->next = new ListNode(1);
		}
		int v1 = 0;
		int v2 = 0;
		if (l1) v1 = l1->val;
		if (l2) v2 = l2->val;
		int res = v1 + v2;
		if (carry) ++res;
		if (res >= 10) {
			carry = true; res = res % 10;
		}	else{
			carry = false;
		}
		cur->next = new ListNode(res);
		cur = cur->next;
		if (l1)l1 = l1->next;
		if(l2) l2 = l2->next;
	}

	return result.next;
}
