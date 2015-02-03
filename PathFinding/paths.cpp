#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
using namespace std;

/*In a 2D matrix consisting of 1s and 0s where 1 is a valid cell, and 0 isn't, return number of paths*/
int numpathutil(vector<vector<int>>& v, int i, int j, int count){
	int num_rows = v.size();
	int num_cols = v.at(0).size();
	/*if ((i < 0) || (i >= num_rows) || (j < 0) || (j >= num_cols)) return 0;
	else if (i == num_rows && j == num_cols) return ++count;
	else if (v[i][j] == 1) return numpathutil(v, i + 1, j, count) + numpathutil(v, i, j + 1, count);
	else if (v[i][j] == 0)return numpathutil(v, i - 1, j, count) + numpathutil(v, i, j - 1, count);*/

	if ((i < 0) || (i >= num_rows) || (j < 0) || (j >= num_cols)) return 0;
	if (i == num_rows-1 && j == num_cols-1) return ++count;
	if (i + 1 < num_rows && v[i + 1][j] == 1){
			count = numpathutil(v, i + 1, j, count);	
	}
	if (j + 1 < num_cols && v[i][j + 1] == 1){
			count = numpathutil(v, i, j + 1, count);
	}
	return count;
}

/*In a 2D matrix consisting of 1s and 0s where 1 is a valid cell, and 0 isn't, return true if a valid path exists from (0,0)
 to (num_rows-1, num_cols-1)*/
bool doespathexist(vector<vector<int>> v, int i, int j){
	int num_rows = v.size();
	int num_cols = v.at(0).size();
	if ((i < 0) || (i >= num_rows) || (j < 0) || (j >= num_cols)) return false;
	else if (i == num_rows - 1 && j == num_cols - 1) return true;
	else if (i + 1 < num_rows && j+1 < num_cols && v[i + 1][j] == 1 && v[i][j+1] == 1){
		return doespathexist(v, i + 1, j) || doespathexist(v, i, j + 1);
	}
	else if (i + 1 < num_rows && v[i + 1][j] == 1){
		return doespathexist(v, i + 1, j);
	}
	else if (j + 1 < num_cols && v[i][j + 1] == 1){
		return doespathexist(v, i, j + 1);
	}
	else{
		return false;
	}
}

int numpaths(vector<vector<int>> v){
	//cout << numpathutil(v, 0, 0, 0) << endl;
	cout << doespathexist(v, 0, 0);
	return 0;
}

static vector<pair<int, int>> posns;

/*Find a path in a maze of 1s and 0s where 1s can be crossed and 0s can't */
bool pathexist(vector<vector<int>> v, int i, int j){
	int num_rows = v.size();
	int num_cols = v.at(0).size();

	if (i == 0 && j == 0){
		for (int i = 0; i < posns.size(); ++i) cout << posns[i].first << " " << posns[i].second << endl;
	}

	if ((i < 0) || (i >= num_rows) || (j < 0) || (j >= num_cols)){
		return false;
	}
	if (i == num_rows - 1 && j == num_cols - 1){
		for (int i = 0; i < posns.size(); ++i) cout << posns[i].first << " " << posns[i].second << endl;
		return true;
	}
	if (i + 1 < num_rows && j + 1 < num_cols && v[i + 1][j] == 1 && v[i][j + 1] == 1){
		posns.push_back(make_pair(i, j));
		return pathexist(v, i + 1, j) || pathexist(v, i, j + 1);
	}
	if (i + 1 < num_rows && v[i + 1][j] == 1){
		posns.push_back(make_pair(i, j));
		return pathexist(v, i + 1, j);
	}
	if (j + 1 < num_cols && v[i][j + 1] == 1){
		posns.push_back(make_pair(i, j));
		return pathexist(v, i, j + 1);
	}
   return false;
}


void main(){
	vector<vector<int>> v = {
			{1, 1, 1},
			{1, 0, 1},
			{ 1, 0, 1 },
			{1, 1, 1}
	};
	//numpaths(v);
	pathexist(v, 0, 0);
	system("PAUSE");
}
