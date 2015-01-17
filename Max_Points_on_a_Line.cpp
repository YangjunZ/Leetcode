#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;
// https://oj.leetcode.com/problems/max-points-on-a-line/


// Definition for a point.
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:

	double calcSlope(Point p1, Point p2)
	{
		//(y2-y1)/(x2-x1), y1-x1*(y2-y1)/(x2-x1)

		if (p1.x == p2.x) {
			return std::numeric_limits<double>::max();
		} else {
			return ((double)(p1.y - p2.y)) / (p1.x - p2.x);
		}
	}



	int maxPoints(vector<Point> &points)
	{
		//for each pair piont p1,p2,calc y=kx+b
		//match the k,b, if k,b is equal,  p1,p2 ,p3, p4 is in the same straight line, linecnt ++
		// get the maximun cnt straight line, (n-1)*n/2 = maximun cnt, n is the maximun number of points

		int maxCnt = 0;
		if (points.size() > 0)
			maxCnt = 1;
		double slope;
		int sameCnt = 0;
		int tmpSlopeCnt = 0;
		for (int i = 0; i < points.size(); i++) {
			map< double, int> slopeMap;
			sameCnt = 1; // the same with himself
			tmpSlopeCnt = 0;
			for (int j = i + 1; j < points.size(); j++) {
				if (points[i].x == points[j].x && points[i].y == points[j].y) {
					sameCnt ++;
				} else {
					slope = calcSlope(points[i], points[j]);
					if ( slopeMap.find(slope) != slopeMap.end()) {
						slopeMap[ slope] = slopeMap[ slope] + 1;
					} else {
						slopeMap[ slope] = 1;
					}
					if (tmpSlopeCnt < slopeMap[ slope] )
						tmpSlopeCnt = slopeMap[slope] ;
				}				
			}
			if( maxCnt < tmpSlopeCnt + sameCnt)
				maxCnt = tmpSlopeCnt + sameCnt;
			slopeMap.clear();
		}
		// return calcMaxPoints( maxCnt);
		return maxCnt;
	}

	void test()
	{
		std::vector<Point> v;
		Point p1(1, 1);
		Point p2(2, 2);
		Point p3(1, 1);
		v.push_back(p1);
		v.push_back(p2);
		v.push_back(p3);
		cout << maxPoints(v) << endl;
	}
};

int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	// Line l1;
	// l1.k = 5;
	// l1.b = 2;
	// Line l2;
	// l2.k = 3;
	// l2.b = 5;
	// if ( l1 < l2)
	//      cout << "l1<l2" << endl;
	// else
	//      cout << "l1>l2" << endl;
	return 0;
}