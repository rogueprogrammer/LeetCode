#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <Queue> 
#include <math.h>
#include <map>
using namespace std;

//http://www.geeksforgeeks.org/snake-ladder-problem-2/

//NOT WORKING - NEED TO FIX. General Algo is correct.


//Use Breadth first traversal to find shortest path in graph

vector<int> moves;
#define N 30

void init(){

	for (int i = 0; i < N; ++i){
		moves.push_back(-1);
	}

	//Ladders:
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	//Snakes:
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;
}

/*
Push 0. Push 1,2,3,4,5,6 
For 2

*/

struct v{
	int vertex;
	int distance;
	v(int _v, int _d): vertex(_v), distance(_d){}
};

vector<bool> visited;

int SnakesAndLadders(vector<int> moves){

	int num_moves = INT_MAX;

	for (int i = 0; i < N; ++i) visited.push_back(false);
	queue<v> vertices;

	v first(0,0); 
	vertices.push(first);

	while (!vertices.empty()){
		v cur = vertices.front();
		if (cur.vertex == 29){
			if (cur.distance < num_moves) num_moves = cur.distance;
		}
		vertices.pop();
		if (moves[cur.vertex] == -1){
			for (int i = 1; i <= 6; ++i){
				if (cur.vertex + i > 29) break;
				v new_v(cur.vertex + i, cur.distance + 1);
				vertices.push(new_v);
			}
		} else{
			v new_v(moves[cur.vertex], cur.distance);
			vertices.push(new_v);
		}
	}

	return num_moves;
}




int main(){

	init();
	cout << SnakesAndLadders(moves) << endl;

	return 0;
}
