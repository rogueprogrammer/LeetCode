#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;

//https://leetcode.com/problems/max-points-on-a-line/

//Idea - start from a point A, go to all points after A (A_prime) and compute the slope between A_prime and A
//Store slopes in hashtable, each time encountering it, increasing the count by 1
//Cover cases of duplicate points, vertical and horizontal lines

struct Point{
	int x;
	int y;
	Point(int r, int c) : x(r), y(c){}
	bool operator == (const Point& rhs) const{
		return x == rhs.x && y == rhs.y;
	}
};


static bool compare (const Point& a, const Point& b) {
	return a.x < b.x;
}


float calculateSlope(const Point a, const Point b){
	return (float)((a.y - b.y) / (a.x - b.x));
}


int maxPoints(vector<Point>& points) {
	if (points.size() == 0) return 0;
	if (points.size() == 1) return 1;
	sort(points.begin(), points.end(), compare);
	
	int max_points = INT_MIN;
	
	for (int i = 0; i < points.size(); ++i){
		Point a = points[i];
		unordered_map<float, int> slopes; //slope -> hits
		unordered_map<int, int> verticals; //x coord -> hits
		unordered_map<int, int> horizontals; //y coord -> hits
		int duplicates = 0;
		for (int j = i + 1; j < points.size(); ++j){
			Point b = points[j];
			if (b.x == a.x && b.y == a.y){
				++duplicates;
			}
			else if (a.x == b.x){ // A and B form a vertical line
				auto it = verticals.find(a.x);
				it == verticals.end() ? verticals[a.x] = 2 : ++verticals[a.x];
				max_points = max(max_points, verticals[a.x] + duplicates);
			}
			else if (a.y == b.y){ //A and B form a horizontal line
				auto it = horizontals.find(a.y);
				it == horizontals.end() ? horizontals[a.y] = 2 : ++horizontals[a.y];
				max_points = max(max_points, horizontals[a.y] + duplicates);
			}
			else{
				float slope = calculateSlope(a, b);
				auto it = slopes.find(slope);
				it == slopes.end() ? slopes[slope] = 2 : ++slopes[slope];
				max_points = max(max_points, slopes[slope] + duplicates);
			}
		}
		if (slopes.size() == verticals.size() == horizontals.size() == 0){
			max_points = max(max_points, duplicates + 1);
		}
	}

	return max_points;
}


