#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
#define DEBUG_1D(x) for(int i = 0; i < x.size(); ++i){cout << x[i] << " ";} cout << endl;
#define DEBUG_2D(x) for(int i = 0; i < x.size(); ++i){ for(int j = 0; j < x[0].size(); ++ j){cout << x[i][j] << " ";} cout << endl;}
//Return true if all ones in a n by n matrix are interconnected neighbors (adjacent directly to the right, left, bottom, or up)

//create my own hash function, since C++ doesnt have a hash for unordered_set<pair<int, int>
struct pair_hash {
	inline size_t operator()(const std::pair<int, int> & v) const {
		return v.first * 311 + v.second;
	}
};

unordered_set<pair<int, int>, pair_hash> visited;

void DFS(vector<vector<int>> M, int row, int col, bool& flagged, int& count, int numOnes){

	if (row == 0 && col == 0){
		visited.insert(make_pair(row, col));
	}

	if (count == numOnes){
		flagged = true;
	}

	if (row >= 1 && M[row - 1][col] == 1) {
		auto it = visited.find(make_pair(row - 1, col));
		if (it == visited.end()){
			++count;
			visited.insert(make_pair(row - 1, col));
			DFS(M, row - 1, col, flagged, count, numOnes);
		}
	}
	if (row <= M.size() - 2 && M[row + 1][col] == 1){
		auto it = visited.find(make_pair(row + 1, col));
		if (it == visited.end()){
			++count;
			visited.insert(make_pair(row + 1, col));
			DFS(M, row + 1, col, flagged, count, numOnes);
		}
	}
	if (col >= 1 && M[row][col - 1] == 1){
		auto it = visited.find(make_pair(row, col - 1));
		if (it == visited.end()){
			++count;
			visited.insert(make_pair(row, col - 1));
			DFS(M, row, col - 1, flagged, count, numOnes);
		}

	}
	if (col <= M.size() - 2 && M[row][col + 1] == 1){
		auto it = visited.find(make_pair(row, col + 1));
		if (it == visited.end()){
			++count;
			visited.insert(make_pair(row, col + 1));
			DFS(M, row, col + 1, flagged, count, numOnes);
		}
	}
}

bool IsConnected(vector<vector<int>> M){
	int numOnes = 0;
	for (int i = 0; i < M.size(); ++i){
		for (int j = 0; j < M.size(); ++j){
			if (M[i][j] == 1) ++numOnes;
		}
	}
	for (int i = 0; i < M.size(); ++i){
		for (int j = 0; j < M.size(); ++j){
			if (M[i][j] == 1){
				bool flagged = false;
				int count = 1;
				DFS(M, 0, 0, flagged, count, numOnes);
				return flagged;
			}
		}
	}
}

int main(){

	vector<vector<int>> M = {
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{1, 1, 0, 0}
	};
	/*vector<vector<int>> M = {
			{ 1, 1, 0, 1 },
			{ 1, 0, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 1 }
	};*/
	cout << IsConnected(M) << endl;

	return 0;
}
