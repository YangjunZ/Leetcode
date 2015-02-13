#include <iostream>
#include <vector>

using namespace std;

// https://oj.leetcode.com/problems/gray-code/
// 0
// 1
// 00
// 01
// 11
// 10

// 000
// 001
// 011
// 010
// 110
// 111
// 101
// 100

// 0000
// 0001
// 0011
// 0010
// 0110
// 0111
// 0101
// 0100
// 1100
// 1101
// 1111
// 1110
// 1010
// 1011
// 1001
// 1000


//bug free: n==0, graycode: 0
class Solution
{
public:
	vector<int> grayCode( int n )
	{
		vector<int> res;
		
		res.push_back( 0 );
		// res.push_back(1);
		int size ;
		for ( int i = 0; i < n; ++i ) {
			size = res.size();
			for ( int j = size - 1; j >= 0; --j ) {
				res.push_back( res[j] + ( 1 << i ) );
			}
		}
		return res;
	}
};
void print( vector<int> vct )
{
	for ( int i = 0; i < vct.size(); ++i ) {
		cout << vct[i] << ",";
	}
	cout << endl;
}
int main( int argc, char const *argv[] )
{
	cout << ( 1 << 0 ) << endl;
	Solution ss;
	print ( ss.grayCode( 1 ) );
	print ( ss.grayCode( 2 ) );
	print ( ss.grayCode( 3 ) );
	print ( ss.grayCode( 4 ) );
	print ( ss.grayCode( 5 ) );
	print ( ss.grayCode( 6 ) );
	cout << "hello world" << endl;
	return 0;
}