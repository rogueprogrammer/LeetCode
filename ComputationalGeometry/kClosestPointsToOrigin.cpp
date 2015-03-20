#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <Queue> //priority queue
#include <math.h>
using namespace std;


//k closest points to the origin:
/*
Given an unsorted array containing coordinates of points in 2D space and a positive number k,
we are asked to find the k closest points to the origin (0,0).
*/


struct Point{
public:
	double x, y;
	double distance;
	Point(double _x,double _y) : x(_x), y(_y){
		distance = sqrt(pow(x, 2) + pow(y,2)   ); 
	}
};


//Solution 1 - Use a max heap to store k points.
//Time complexity - O(nlogk), Space: O(k)
class Compare{
public:
	bool operator()(const Point& p1, const Point& p2){
		return p1.distance > p2.distance; //max heap property
	}
};

vector<Point> k_ClosestPointsToOrigin(vector<Point> points, int k){
	vector<Point> res;
	priority_queue<Point, vector<Point>, Compare> max_heap;
	for(int i = 0; i < points.size(); ++i){
		if (!max_heap.empty()){
			if (max_heap.size() < k){
				max_heap.push(points[i]);
			}
			else{
				if (max_heap.top().distance > points[i].distance){
					max_heap.pop();
					max_heap.push(points[i]);
				}
			}
		}
		else{
			max_heap.push(points[i]);
		}
	}
	//copy contents of max_heap into res

	while (!max_heap.empty()){
		Point cur = max_heap.top();
		res.push_back(cur);
		max_heap.pop();
	}

	return res;
}

//Solution 2 - QuickSelect Algorithm





void main(){


	Point p1(1, 1);
	Point p2(2, 2);
	Point p3(3, 3);
	Point p4(4, 4);
	Point p5(5, 5);
	Point p6(6, 6);
	Point p7(7, 7);
	Point p8(8, 8);
	Point p9(9, 9);

	vector<Point> points; 
	points.push_back(p1); points.push_back(p2); points.push_back(p3); 
	points.push_back(p4); points.push_back(p5); points.push_back(p6); 
	points.push_back(p7); points.push_back(p8); points.push_back(p9);

	int k = 3;
	vector<Point> res = k_ClosestPointsToOrigin(points, k);
	for (int i = 0; i < res.size(); ++i){
		cout << res[i].x << "  " << res[i].y << endl;
	}

}
