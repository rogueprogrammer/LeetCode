#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> perms;

void AllPerms(string str, int posn){
	if (posn == str.size() - 1) return;

	for (int i = posn; i < str.size(); ++i){
		std::swap(str[posn], str[i]);
		perms.insert(str);
		AllPerms(str, posn + 1);
		swap(str[posn], str[i]);
	}
}



int main(){
	string str = "ABCD";
	AllPerms(str, 0);
	cout << perms.size() << endl;
	for (auto it : perms){
		cout << it << endl;
	}
}
