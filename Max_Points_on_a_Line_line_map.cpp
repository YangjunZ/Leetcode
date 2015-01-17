#include <iostream>
#include <vector>
#include <map>


using namespace std;
// https://oj.leetcode.com/problems/max-points-on-a-line/
//not accepted, some problems

// Definition for a point.
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct Line {
	float k;
	float b;
	float x0;
	int isX0;
	Line(): k(0), b(0), x0(0), isX0(0) {};
	//for line x=x0, isX0 = 1, k=0, b=0, and for line y=kx+b, x0=0, isX0=0;
	bool operator < ( const Line &l2) const
	{
		if ( isX0 == 1 && l2.isX0 == 1) {
			if ( x0 <= l2.x0)
				return true;
			else
				return false;
		}
		if (isX0 == 1 && l2.isX0 == 0)
			return true;
		if (isX0 == 0 && l2.isX0 == 1)
			return false;
		if (k < l2.k )
			return true;
		if (k == l2.k && b <= l2.b)
			return true;
		return false;
	};
};

struct Comp {
	/* data */
	// int a;
	bool operator ()(const Line &l1, const Line &l2)const
	{
		if ( l1.isX0 == 1 && l2.isX0 == 1) {
			if ( l1.x0 <= l2.x0)
				return true;
			else
				return false;
		}
		if (l1.isX0 == 1 && l2.isX0 == 0)
			return true;
		if (l1.isX0 == 0 && l2.isX0 == 1)
			return false;
		if (l1.k < l2.k )
			return true;
		if (l1.k == l2.k && l1.b <= l2.b)
			return true;
		return false;
	}
};



class Solution
{
public:

	Line calcLine(Point p1, Point p2)
	{
		//(y2-y1)/(x2-x1), y1-x1*(y2-y1)/(x2-x1)
		Line tmp;
		if (p1.x == p2.x){
			tmp.isX0 = 1;
			tmp.x0 = p1.x;
		}else{
			tmp.k = (p1.y - p2.y) / (p1.x - p2.x);
			tmp.b = p1.y - p1.x * tmp.k;
		}
		return tmp;
	}



	int maxPoints(vector<Point> &points)
	{
		//for each pair piont p1,p2,calc y=kx+b
		//match the k,b, if k,b is equal,  p1,p2 ,p3, p4 is in the same straight line, linecnt ++
		// get the maximun cnt straight line, (n-1)*n/2 = maximun cnt, n is the maximun number of points
		map< Line, int> lineMap;
		Line tmpLine;
		int maxCnt = 0;
		for (int i = 0; i < points.size(); i++) {
			for (int j = i + 1; j < points.size(); j++) {
				tmpLine = calcLine(points[i], points[j]);
				cout << "tmpLine" << tmpLine.k << endl;
				if ( lineMap.find( tmpLine) != lineMap.end()) {
					cout << "1find line: " << lineMap[tmpLine] << endl;
					lineMap[tmpLine] = lineMap[ tmpLine] + 1;
				} else {
					lineMap[tmpLine] = 1;
					cout << "lineMap size " << lineMap.size() << endl;
					cout << "2find line: " << lineMap[tmpLine] << endl;
				}

				if (lineMap[tmpLine] > maxCnt) {
					maxCnt = lineMap[tmpLine];
				}
			}
		}

		// return calcMaxPoints( maxCnt);
		return maxCnt;
	}

	void test()
	{
		std::vector<Point> v;
		Point p1(1, 1);
		Point p2(2, 2);
		Point p3(3, 3);
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
	Line l1;
	l1.k = 5;
	l1.b = 2;
	Line l2;
	l2.k = 3;
	l2.b = 5;
	if ( l1 < l2)
		cout << "l1<l2" << endl;
	else
		cout << "l1>l2" << endl;
	return 0;
}