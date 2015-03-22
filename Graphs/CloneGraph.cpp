#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <Queue> 
#include <math.h>
using namespace std;

struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x){}
};

//https://leetcode.com/problems/clone-graph/

unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it;

//Apply DFS to clone the graph. Keep track of visited nodes to avoid cycles
UndirectedGraphNode* CloneGraph(UndirectedGraphNode* node){
	it = visited.find(node);
	if (it == visited.end()){ //node is not visited

		UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
		visited.insert(make_pair(node, node));
		for (int i = 0; i < node->neighbors.size(); ++i){
			root->neighbors.push_back(node->neighbors[i]);
			CloneGraph((UndirectedGraphNode*)node->neighbors[i]);
		}
	}
	return node;
}


unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited2;
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it2;

void PrintGraph(UndirectedGraphNode* root){
	if (!root) return;
	it2 = visited2.find(root);

	if (it2 == visited2.end()){
		visited2.insert(make_pair(root, root));
		cout << root->label << "-> {";
		for (int i = 0; i < root->neighbors.size(); ++i){
			UndirectedGraphNode* cur = root->neighbors[i];
			cout << cur->label << ", ";
		}
		cout << endl;
		for (int i = 0; i < root->neighbors.size(); ++i){
			UndirectedGraphNode* cur = root->neighbors[i];
			PrintGraph(cur);
		}
	}
}




int main(){
	//a->b->c

	UndirectedGraphNode* a = new UndirectedGraphNode(1);
	UndirectedGraphNode* b = new UndirectedGraphNode(2);
	UndirectedGraphNode* c = new UndirectedGraphNode(3);
	UndirectedGraphNode* d = new UndirectedGraphNode(4);
	UndirectedGraphNode* e = new UndirectedGraphNode(5);


	a->neighbors.push_back(b);
	b->neighbors.push_back(c);
	b->neighbors.push_back(a);
	c->neighbors.push_back(d);
	d->neighbors.push_back(e);
	e->neighbors.push_back(a);
	//PrintGraph(a);

	UndirectedGraphNode* res = CloneGraph(a);
	PrintGraph(res);

}
