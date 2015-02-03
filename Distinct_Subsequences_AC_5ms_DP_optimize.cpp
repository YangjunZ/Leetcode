#include <iostream>
#include <vector>

using namespace std;

// https://oj.leetcode.com/problems/distinct-subsequences/

class Solution
{
public:
	int numDistinct( string S, string T )
	{
		if ( T.size() == 0 )
			return 1;
		if ( S.size() == 0 )
			return 0;
		int tSize = T.size();
		int sSize = S.size();
		int low = 0, up = S.size() - 1;

		while ( low < sSize && S[low] != T[0] ) low++; 
		while ( up >= low && S[up] != T[tSize - 1] ) up--;

		vector<int> res( tSize + 1, 0 );
		res[0] = 1;
		for ( int ss = low; ss <= up; ++ss )
			for ( int tt = ( ss - low + 1 < tSize ? ss - low + 1 : tSize ); tt >= 1; --tt )
			// for ( int tt = tSize; tt >= 1; --tt )
				res[tt] = res[tt] + ( ( S[ss] == T[tt - 1] ) ? res[tt - 1] : 0 );
		return res[tSize];
	}
};

int main( int argc, char const *argv[] )
{
	string S = "rabbbit";
	string T = "rabbit";
	Solution ss;
	cout << ss.numDistinct( S, T ) << endl;
	return 0;
}
