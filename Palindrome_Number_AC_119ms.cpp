#include <iostream>
#include <climits>
using namespace std;

// https://oj.leetcode.com/problems/palindrome-number/
//bug free: negative

class Solution
{
public:
	bool isPalindrome( int x )
	{
		// if(x==-2147447412 || x==-101) return false;
		if ( x < 0 || ( x != 0 && x % 10 == 0 ) ) return false;
		int rev = 0;
		while ( x > rev ) {
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		return x == rev || x == rev / 10;
	}

	bool isPalindrome2( int x )
	{
		if ( x < 0 || ( x != 0 && x % 10 == 0 ) ) return false;
		int rev = 0;
		while ( x > rev ) {
			rev = rev * 10 + x % 10;
			x = x / 10;
		}
		return ( x == rev || x == rev / 10 );
	}
};


int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	cout << ss.isPalindrome( 10 ) << endl;
	cout << ss.isPalindrome( 11 ) << endl;
	cout << ss.isPalindrome( -10 ) << endl;
	cout << ss.isPalindrome( -11 ) << endl;
	cout << ss.isPalindrome( -121 ) << endl;
	cout << ss.isPalindrome( -1231 ) << endl;
	cout << ss.isPalindrome( -1221 ) << endl;
	cout << ss.isPalindrome( 1234321 ) << endl;
	cout << ss.isPalindrome( 0 ) << endl;

	//  Input:  -2147447412
	// Output:  true
	// Expected:    false
	cout << -1 << " " << 0x80000000 << endl;
	cout << -1 << " " << INT_MIN << endl;
	cout << 0x7fffffff << endl;
	cout << ss.isPalindrome( -2147447412 ) << endl;
	cout << ss.isPalindrome2( -2147447412 ) << endl;
	cout << ss.isPalindrome( -101 ) << endl;
	cout << ss.isPalindrome2( -101 ) << endl;
	return 0;
}


