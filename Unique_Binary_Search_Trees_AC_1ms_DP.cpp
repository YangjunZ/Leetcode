#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
	int numTrees( int n )
	{
		//a[i] store the number of unique binary search trees with value 1..i,
		//a[0] = 0,a[1]=1, a[n]= 2* a[n-1]+ sigma( a[i]* a[n-1-i])
		//for 2*a[n-1], add n to the top or right position of a[n-1] BST.
		//for sigma(a[i]*a[n-1-i]), tree is constructed by 1..i, n, i+1..n-1
		// an = 2*an-1 + (n-2)
		vector<int> dp;
		dp.push_back( 0 );
		dp.push_back( 1 );
		int tmp;
		for ( int i = 2; i <= n; ++i ) {
			tmp = 0;
			for ( int j = 1; j < i; ++j )
				tmp += dp[j] * dp[i - j -1];
			dp.push_back( tmp + 2*dp[i - 1] );
		}
		return dp[n];
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	cout << ss.numTrees( 1 ) << endl;
	cout << ss.numTrees( 2 ) << endl;
	cout << ss.numTrees( 3 ) << endl;
	cout << ss.numTrees( 4 ) << endl;
	cout << ss.numTrees( 5 ) << endl;
	cout << ss.numTrees( 6 ) << endl;
	cout << ss.numTrees( 7 ) << endl;
	cout << "hello world" << endl;
	return 0;
}