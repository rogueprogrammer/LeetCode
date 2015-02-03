#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


vector<vector<int> > generate(int numRows) {
	vector<vector<int>> res(numRows);
	for (int i = 0; i < numRows; i++) {
		res[i].resize(i + 1);
		res[i][0] = res[i][i] = 1;

		for (int j = 1; j < i; j++)
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];

		//for LC-119 (Extension of Pascal's triangle)
		//if (i >= 2) {
			//res[i-1].erase(res[i-1].begin(), res[i-1].end());
			//res[i - 2].erase(res[i - 2].begin(), res[i - 2].end());
		//}
	}
	return res;
}
