#include <iostream>
#include <vector>

using namespace std;
// Longest Palindromic Substring
// https://oj.leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
	string longestPalindrome( string s )
	{
		if ( s.size() <= 1 )
			return s;
		int len = s.size();
		cout << "len:" << len << endl;
		vector< vector< bool> > isPalindrome( len,
		                                      vector<bool>( len, false ) );
		//isPalindrome[i][j] store whether s[i,j] is a palindrome
		isPalindrome[0][0] = true;
		// string res = s[0];
		int max = 1;
		int max_s = 0;
		for ( int i = 1; i < len; i++ ) {
			isPalindrome[i][i] = true;
			if ( s[i] == s[i - 1] ) {
				isPalindrome[i - 1][i] = true;
				max = 2;
				max_s = i - 1;
			}
		}
		for ( int l = 3; l <= len; ++l ) {
			for ( int i = 0; i + l <= len; ++i ) {
				int j = i + l - 1;
				if ( isPalindrome[i + 1][j - 1] && s[i] == s[j] ) {
					isPalindrome[i][j] = true;
					if ( max < l ) {
						max = l;
						max_s = i;
					}
				}
			}
		}
		cout << max_s << "," << max << endl;
		return s.substr( max_s, max );
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	string str = "iooerbarep";
	string str2 = "iptmykvjanwiihepqhzupneckpzomgvzmyoybzfynybpfybngttozprjbupciuinpzryritfmyxyppxigitnemanreexcpwscvcwddnfjswgprabdggbgcillisyoskdodzlpbltefiz";
	string str3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	Solution ss;
	cout << ss.longestPalindrome( str ) << endl;
	cout << ss.longestPalindrome( str2 ) << endl;
	cout << ss.longestPalindrome( str3 ) << endl;
	return 0;
}