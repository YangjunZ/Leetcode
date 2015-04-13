#include <iostream>

using namespace std;

// https://leetcode.com/problems/length-of-last-word/

class Solution
{
public:
	int lengthOfLastWord( const char *s )
	{
		//count the length of last word
		int last_len = 0;
		int tmp_len = 0;
		for ( int i = 0; s[i] != '\0'; ++i ) {
			if ( s[i] != ' ' )
				tmp_len ++;
			else {
				if ( tmp_len != 0 )
					last_len = tmp_len;
				tmp_len = 0;
			}
		}
		if ( tmp_len != 0 )
			last_len = tmp_len;
		return last_len;
	}
	void run( const char *s )
	{
		cout << lengthOfLastWord( s ) << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	// ss.run( "hello wolrdxxx axx  " );
	ss.run( "" );
	return 0;
}