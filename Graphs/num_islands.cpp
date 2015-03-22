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

#define rows 5
#define cols 5


//Given a 2d matrix, find the number of islands. 
//http://www.geeksforgeeks.org/find-number-of-islands/

bool graph[rows][cols] = 
{ 
	{ 1, 1, 0, 0, 0 },
	{ 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 1 },
	{ 0, 0, 0, 0, 0 },
	{ 1, 0, 1, 0, 1 }
};


/*
- DFS. Keep track of visited nodes as to not revisit same node
*/
struct Point{
	int row;
	int col;
	Point(int r, int c) : row(r), col(c){}
};

map<pair<int, int>, Point*> visited;
map<pair<int, int>, Point*>::iterator it;

 static int num_islands = 0;


void DFS(bool graph[rows][cols], int row, int col){
	if (graph[row][col] == 0) return; //safety check, but should never get hit

	if (graph[row][col] == 1){
		visited[make_pair(row, col)] = new Point(row, col); //insert in list of visited nodes
	}

	//check up
	if (row - 1 >= 0 && graph[row-1][col] == 1){
		it = visited.find(make_pair(row - 1, col));
		if (it == visited.end()){
			DFS(graph, row - 1, col);
		}
	}

	//check up left diag
	if (row - 1 >= 0 && col - 1 >= 0 && graph[row - 1][col-1] == 1){
		it = visited.find(make_pair(row - 1, col-1));
		if (it == visited.end()){
			DFS(graph, row - 1, col-1);
		}
	}

	//check left
	if (col - 1 >= 0 && graph[row][col - 1] == 1){
		it = visited.find(make_pair(row, col - 1));
		if (it == visited.end()){
			DFS(graph, row, col - 1);
		}
	}


	//check right
	if (col + 1 <= cols-1 && graph[row][col + 1] == 1){
		it = visited.find(make_pair(row, col + 1));
		if (it == visited.end()){
			DFS(graph, row, col + 1);
		}
	}

	//check up right diag
	if (row - 1 >= 0 && col + 1 <= cols - 1 && graph[row-1][col + 1] == 1){
		it = visited.find(make_pair(row-1, col + 1));
		if (it == visited.end()){
			DFS(graph, row-1, col + 1);
		}
	}


	//check down
	if (row + 1 <= rows - 1 && graph[row+1][col] == 1){
		it = visited.find(make_pair(row+1, col));
		if (it == visited.end()){
			DFS(graph, row+1, col);
		}
	}


	//check down left diag
	if (col - 1 >= 0 && row + 1 <= rows - 1 && graph[row + 1][col-1] == 1){
		it = visited.find(make_pair(row + 1, col-1));
		if (it == visited.end()){
			DFS(graph, row + 1, col-1);
		}
	}


	//check down right diag
	if (col + 1 >= cols-1 && row + 1 <= rows - 1 && graph[row + 1][col + 1] == 1){
		it = visited.find(make_pair(row + 1, col + 1));
		if (it == visited.end()){
			DFS(graph, row + 1, col + 1);
		}
	}
}


int NumberOfIslands(bool graph[rows][cols]){

	for (int row = 0; row < rows; ++row){
		for (int col = 0; col < cols; ++col){
			it = visited.find(make_pair(row, col));
			if ((graph[row][col] == 1) && (it == visited.end())){
				++num_islands;
				DFS(graph, row, col);
			}

		}

	}

	return num_islands;

}



int main(){
	int num_rows = sizeof(graph) / sizeof(graph[0]);
	int num_cols = sizeof(graph[0]) / sizeof(graph[0][0]);

	cout << NumberOfIslands(graph) << endl; 

	return 0;
}
