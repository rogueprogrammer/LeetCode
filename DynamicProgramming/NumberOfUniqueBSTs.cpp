#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/unique-binary-search-trees/
/* Given n, how many unique BSTs can be constructed with nodes 1, ..., n?
We can use recursion or DP.
Store the count of the number of unique BSTS in an array.
Let DP[i] = # of BSTs of length i
Consider an example. Lets say we want to compute DP[3], this means number of BSTs of length 3. 
For simplicity, the nodes we are considering are 1,2, and 3.
We would have to consider each node as a root, and count the number of nodes in the left subtree and multiply it with 
number of nodes in the right subtree (CARTESIAN PRODUCT) to consider all possibilities. 
So DP[3] = (DP[0] * DP[2])         , 1 is root, left subtree has 0 nodes, right subtree has 2 nodes
+ (DP[1] * DP[1]) , 2 is root, left subtree has 1 node, right subtree has 3 nodes
+ (DP[2] * DP[0]), 3 is root, left subtree has 2 nodes, right subtree has 0 nodes.

Similarily, DP[4]
= DP[0]*DP[3]       , 1 is root
+ DP[1]*DP[2]               , 2 is root
+ DP[2]*DP[1]             , 3 is root
+ DP[3]*DP[0]              , 4 is root

*/

int numTrees(int n){

	vector<int> DP(n+1);
	DP[0] = 1; 
	DP[1] = 1;
	for (int i = 2; i <= n; ++i){
		int res = 0;
		for (int j = 0; j < i; ++j){
			res += DP[j] * DP[i - j-1];
		}
		DP[i] = res;
	}
	return DP[n];
}

