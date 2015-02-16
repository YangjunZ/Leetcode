#include <iostream>
#include <climits>
using namespace std;

// Reverse Integer
// https://oj.leetcode.com/problems/reverse-integer/

class Solution
{
public:
	int reverse( int x )
	{
		if ( -10 < x && x < 10 )
			return x;
		if( x==INT_MIN )
			return 0;
		long long res = 0;
		int isNegative = false;
		if ( x < 0 ) {
			isNegative = true;
			x = -x;
		}
		int tmp;
		while ( x ) {
			tmp = x % 10;
			x = x / 10;
			res = res * 10 + tmp;
		}
		if (res > INT_MAX)
			return 0;
		if ( isNegative ) {
			res = -res;
		}
		return res;
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	cout << ss.reverse( -123456 ) << endl;
	cout << ss.reverse( 123456 ) << endl;
	cout << ss.reverse( 1534236469 ) << endl;
	
	int num = 1534236469;
	cout << hex<<num<<endl;
	return 0;
}