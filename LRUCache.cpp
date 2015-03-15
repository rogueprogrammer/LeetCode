#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;



//LRU Cache: Updates recently used element to front of list. When it reaches capacity, deletes least recently used element
//Uses combination of map and doubly linked list.
//When accessing an element in the hash table (which is a list of key value pairs), 
//push that element to front of doubly linked list
//Search elements using HT. Insert or delete data into "data" list


class LRUCache{
	
public:


	int get(int key){
		int res = -1;
		auto it = HT.find(key);

		//if already in hash table, take it out of its current place, and push it to the front
		if (it != HT.end()){
			res = it->second->second;
			HT.erase(it);
			//data.erase(it->second); //SHOULD WORK
			
			//data.push_front(make_pair(key, it->second->second)); //SHOULD WORK
			HT[key] = data.begin();
		}
		return res;
	}
	void insert(int key, int val){
		if (num_elements >= SIZE){
			auto last = data.back();
			int key_last = last.first;
			HT.erase(key_last);
			data.pop_back();		
		}
		auto it = HT.find(key);
		if (it != HT.end()){ //if already in hash table, erase from data
			data.erase(it->second);
		}
		pair<int, int> p = make_pair(key, val);
		data.push_front(p);
		HT[key] = data.begin();
		++num_elements;
	}

	void Print_Cache_Contents(){
		for (auto& x : data){
			cout << "KEY: " << x.first << "     VALUE: " << x.second << endl;
		}
	}


private:
	unordered_map<int, list<pair<int, int>>::iterator > HT; //key, address of DLL node
	list<pair<int, int>> data;
	const int SIZE = 3;
	int num_elements = 0;


};

void main(){
	LRUCache cache;
	cache.insert(1, 100);
	cache.insert(2, 200);
	cache.insert(3, 300);
	cache.insert(4, 400);
	cout << cache.get(3) << endl;

	cache.Print_Cache_Contents();

}
