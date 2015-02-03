#include <iostream>
#include <vector>

using namespace std;

// https://oj.leetcode.com/problems/distinct-subsequences/

class Solution
{
public:
	int numDistinct( string S, string T )
	{
		int sSize = S.size();
		int tSize = T.size();
		vector<int> res( tSize + 1, 0 );
		res[0] = 1;

		for ( int ss = 1; ss <= sSize; ++ss ) {
			for ( int tt = ( ss < tSize ? ss : tSize ); tt > 0; --tt ) {
				res[tt] = res[tt] + ( ( S[ss - 1] == T[tt - 1] ) ? res[tt - 1] : 0 );
			}
		}
		return res[tSize];
	}
};

int main( int argc, char const *argv[] )
{
	string S = "rabbbiit";
	string T = "rabbit";
	Solution ss;
	cout << ss.numDistinct( S, T ) << endl;
	return 0;
}
