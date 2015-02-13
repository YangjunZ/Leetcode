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



// G(i) = i^(i/2)
// 0^0 = 0
// 1^0 = 1
// 2^1 = 3
// 3^1 = 2
// 4^2 = 100 ^ 10 = 6
// 5^2 = 101 ^ 10 = 7
// 6^3 = 110 ^ 11 = 5
// 7^3 = 111 ^ 11 = 4

//bug free: n==0, graycode: 0
class Solution
{
public:
	vector<int> grayCode( int n )
	{
		vector<int> res;
		int max = 1<<n;	
		for ( int i = 0; i < max; ++i ) {
			res.push_back( i^(i>>1));
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
	// cout << ( 1 << 0 ) << endl;
	Solution ss;
	print ( ss.grayCode( 0 ) );
	print ( ss.grayCode( 1 ) );
	print ( ss.grayCode( 2 ) );
	print ( ss.grayCode( 3 ) );
	print ( ss.grayCode( 4 ) );
	print ( ss.grayCode( 5 ) );
	print ( ss.grayCode( 6 ) );
	cout << "hello world" << endl;
	return 0;
}