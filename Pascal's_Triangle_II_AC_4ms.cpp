#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/pascals-triangle/


class Solution
{
public:
	vector<int> getRow( int rowIndex )
	{
		vector<int> v( rowIndex + 1, 0 );
		v[0] = 1;
		if ( rowIndex <= 0 ) return v;
		for ( int i = 1; i <= rowIndex; ++i ) {
			v[i] = 1;
			for ( int j = i - 1; j > 0; --j )
				v[j] = v[j] + v[j - 1];
		}
		return v;
	}

	void print( vector<int> v )
	{
		cout << "[";
		for ( int j = 0; j < v.size(); ++j )
			cout << v[j] << ",";
		cout << "]" << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	ss.print( ss.getRow( 0 ) );
	ss.print( ss.getRow( 2 ) );
	ss.print( ss.getRow( 5 ) );
	return 0;
}