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
		if(x<0) return false;
		int lenCnt = 0;
		int tmpX = x;
		long long base = 1;
		while ( tmpX != 0 ) {
			tmpX /= 10;
			lenCnt ++;
			base *= 10;
		}
		if ( base <= 10 ) //[-9,9]
			return true;

		base = base / 10;
		// cout <<x<<":"<< lenCnt << " " << base << endl;
		while ( lenCnt > 1 &&  x % 10 == ( x / base ) ) {
			x = ( x % base ) / 10;
			base =  base / 100;
			lenCnt -= 2;
			// cout <<x<<":"<< lenCnt << " " << base << endl;
		}

		if ( lenCnt <= 1 )
			return true;
		return false;
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