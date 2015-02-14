#include <iostream>
#include <vector>
using namespace std;

// https://oj.leetcode.com/problems/scramble-string/

//bug free: can only represent tree once,

class Solution
{
public:

	bool isScramble_core( string &s1, string &s2, int b1, int b2, int len )
	{
		int j = 0;
		for ( j = 0; j < len; ++j ) {
			if ( s1[b1 + j] != s2[b2 + j] )
				break;
		}
		if ( j == len ) return true;

		vector<int> count( 257, 0 );
		for ( int i = 0; i < len; ++i ) {
			count[ s1[b1 + i]] ++;
			count[ s2[b2 + i]]--;
		}
		
		for ( int i = 0; i < count.size(); ++i ) {
			if ( count[i] != 0 )
				return false;
		}

		for ( int i = 1; i < len; ++i ) {
			if ( isScramble_core( s1, s2, b1, b2, i ) && isScramble_core( s1, s2, b1  + i, b2 + i , len - i ) )
				return true;
			if ( isScramble_core( s1, s2, b1, b2 + len - i, i ) && isScramble_core( s1, s2, b1 + i, b2 , len - i ) )
				return true;
		}
		return false;
	}


	bool isScramble( string s1, string s2 )
	{
		if ( s1.size() != s2.size() ) return false;
		if ( s1 == s2 ) return true;
		return isScramble_core(s1, s2, 0,0,s1.size());
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	cout << ss.isScramble( "", "" ) << endl;
	cout << ss.isScramble( "abc", "bca" ) << endl;
	cout << ss.isScramble( "great", "rgtae" ) << endl;
	cout << ss.isScramble( "abcd", "bdac" ) << endl;
	return 0;
}