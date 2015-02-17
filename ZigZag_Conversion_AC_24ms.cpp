#include <iostream>

using namespace std;
// ZigZag Conversion

class Solution
{
public:
	string convert( string s, int nRows )
	{
		int len = s.size();
		if ( len <= 1 || nRows == 1 )
			return s;

		int groupLen = ( nRows - 1 ) << 1;
		int groupNum = ( len / groupLen ) + 1;
		string res( len, '\0' );
		int base, index, cnt;
		cnt = 0;
		base = -groupLen;
		for ( int r = 0; r < nRows; ++r ) {
			base = 0 - groupLen;
			for ( int n = 0; n < groupNum; ++n ) {
				base = base + groupLen;
				index = base + r;
				if ( index < len ) {
					res[cnt++] = s[index];
				}
				if ( r == 0 || r == nRows - 1 )
					continue;
				index = ( groupLen - r ) + base;
				if ( index < len ) {
					res[cnt++] = s[index];
				}
			}
		}
		return res;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	string s = "PAYPALISHIRING";

	Solution ss;
	cout << ss.convert( s, 3 ) << endl;
	cout << ss.convert( s, 2 ) << endl;
	cout << ss.convert( s, 1 ) << endl;

	// cout << str << endl;
	// str[1] = 'a';
	// cout << str << endl;
	// string str2( 8, 'a' );
	// cout << str2 << endl;
	return 0;
}