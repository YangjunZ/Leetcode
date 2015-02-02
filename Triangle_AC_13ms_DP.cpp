#include <iostream>
#include <vector>

using namespace std;
// Triangle

// https://oj.leetcode.com/problems/triangle/

class Solution
{
public:
	int minimumTotal( vector<vector<int> > &triangle )
	{
		for ( int i = triangle.size() - 2; i >= 0; --i ) {
			for ( int j = 0; j < triangle[i].size(); ++j ) {
				triangle[i][j] = triangle[i + 1][j] < triangle[i + 1][j + 1] ? triangle[i][j] + triangle[i + 1][j] : triangle[i][j] + triangle[i + 1][j + 1];
			}
		}
		return triangle[0][0];
	}
};


int main( int argc, char const *argv[] )
{
	vector<vector<int> > triangle;
	vector<int> v1 = {2};
	vector<int> v2 = {3, 4};
	vector<int> v3 = {6, 5, 7};
	vector<int> v4 = {4, 1, 8, 3};
	triangle.push_back( v1 );
	triangle.push_back( v2 );
	triangle.push_back( v3 );
	triangle.push_back( v4 );
	Solution ss;
	cout << ss.minimumTotal( triangle ) << endl;
	cout << "hello world" << endl;
	return 0;
}
