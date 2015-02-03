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
		vector< vector<int> > res( tSize + 1, vector<int> ( sSize + 1, 0 ) );
		for ( int ss = 0; ss <= sSize; ++ss )
			res[0][ss] = 1;


		for ( int tt = 1; tt <= tSize; ++tt ) {
			for ( int ss = tt; ss <= sSize; ++ss ) {
				res[tt][ss] = res[tt][ss - 1] + ( ( S[ss - 1] == T[tt - 1] ) ? res[tt - 1][ss - 1] : 0 );
			}
		}
		return res[tSize][sSize];
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
