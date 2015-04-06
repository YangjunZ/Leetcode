#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/longest-valid-parentheses/

class Solution
{
public:
	int longestValidParentheses( string s )
	{
		vector<int> stk;
		stk.push_back( -1 );
		vector<char> stkp;
		for ( int i = 0; i < s.length(); ++i ) {
			if ( s[i] == '(' ) {
				stk.push_back( i );
				stkp.push_back( '(' );
			} else { //s[i] == ')'
				if ( stkp.size() > 0 &&  stkp.back() == '(' ) { //"()"
					stkp.pop_back();
					stk.pop_back();
				} else { //empty or top is ')'
					stkp.push_back( ')' );
					stk.push_back( i );
				}
			}
		}
		stk.push_back( s.length() );
		// for ( int i = 0; i < stk.size(); ++i ) {
		// 	cout << stk[i] << " ";
		// }
		// cout << endl;
		int max = 0;
		for ( int i = 0; i < stk.size() - 1; ++i ) {
			if ( stk[i] == stk[i + 1] || stk[i] == stk[i + 1] + 1 ) {
				continue;
			} else if ( max <  stk[i + 1] - stk[i] - 1 ) {
				max = stk[i + 1] - stk[i] - 1;
			}
		}

		return max;
	}
	void run( string s )
	{
		cout << longestValidParentheses( s ) << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	// string s = ")()())";
// string s = ")(()())(";
string s = "";
	Solution ss;
	ss.run( s );
	return 0;
}