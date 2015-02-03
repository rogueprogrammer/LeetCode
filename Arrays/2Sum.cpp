#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*Strategy - Hashtable O(n) runtime and O(n) space*/

vector<int> 2Sum(vector<int> &numbers, int target){
	vector<int> res;
	map<int, int> ht;
	map<int, int>::iterator it;

	for (int i = 0; i < numbers.size(); ++i){
		int cur = numbers.at(i);
		it = ht.find(target - cur);
		if (it != ht.end()){
			res.push_back(it->second + 1);
			res.push_back(i+1);
			return res;
		}
		else{
			ht.insert(make_pair(cur, i));
		}
	}
	return res;
}
