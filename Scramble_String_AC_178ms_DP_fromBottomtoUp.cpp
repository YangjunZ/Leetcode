#include <iostream>
#include <vector>
using namespace std;

// https://oj.leetcode.com/problems/scramble-string/

//bug free: can only represent tree once,

class Solution
{
public:
	bool isScramble_possible( string &s1, string &s2, int b1, int b2, int len )
	{
		vector<int> count( 257, 0 );
		for ( int i = 0; i < len; ++i ) {
			count[ s1[b1 + i]] ++;
			count[ s2[b2 + i]]--;
		}
		
		for ( int i = 0; i < count.size(); ++i ) {
			if ( count[i] != 0 )
				return false;
		}
		return true;
	}

	bool isScramble( string s1, string s2 )
	{
		if ( s1.size() != s2.size() ) return false;
		if ( s1 == s2 ) return true;
		int len = s1.size();
		vector< vector< vector<bool> > > dp( len,
		                                     vector< vector<bool>>( len,
		                                             vector<bool>( len + 1, false ) ) );
		//dp[i][j][l], s1.substr(i,l) is scramble string of s2.substr(j,l)
		//dp[i][j][l] = V( dp[i][j][k]&&dp[i+k][j+k][l-k]) || V(dp[i][j+l-k][k] && dp[i+k][j][l-k])
		//res is dp[0][0][len]
		for ( int i = len-1; i >=0; --i ) {
			for ( int j = len-1; j >=0; --j ) {
				if (s1[i] == s2[j] )
					dp[i][j][1] = true;
				for ( int l = 2;  i + l <= len && j + l <= len; ++l ) {
					if( isScramble_possible(s1, s2, i, j, l) == false)  //why much slow?
						continue;
					for(int k=1; k<l; ++k){
						if( dp[i][j][k]&& dp[i+k][j+k][l-k]){
							dp[i][j][l] = true;
							break;
						}
						if( dp[i][j+l-k][k]&& dp[i+k][j][l-k]){
							dp[i][j][l] = true;
							break;
						}
					}
				}
			}
		}
		return dp[0][0][len];
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