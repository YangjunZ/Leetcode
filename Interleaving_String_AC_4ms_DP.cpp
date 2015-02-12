#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://oj.leetcode.com/problems/interleaving-string/


class Solution
{
public:
	bool isInterleave( string s1, string s2, string s3 )
	{
		// vector< unordered_map<int , int> > dpmap(2, unordered_map<int, int> ());
		// dpmap[0][-1]=-1;
		if(s1.size() + s2.size() != s3.size())
			return false;

		vector< vector<int>> dp( 2, vector<int>( s1.size()+1, -1 ) ); //dp[0..1][i][j], means s3[0, i+j-1] is formed by the interleaving of s1[0, i) and s2[0,j)  
		int start, to;
		dp[0][0] = 0;  
		for ( int i = 0; i < s3.size(); ++i ) {
			start = i % 2;
			to = ( i + 1 ) % 2;
			// cout <<"idx:" <<s3[i]<<endl;
			// for(int i=0; i<dp[start].size();++i)
			// 	cout << i<<"\t";
			// cout << endl;
			// for(int i=0; i<dp[start].size();++i)
			// 	cout << dp[start][i]<<"\t";
			// cout << endl;
			for ( int j = 0; j <= i && j<=s1.size(); ++j ) {
				if ( dp[start][j] >= 0 ) {
					if ( j<s1.size() && s3[i] == s1[j] )
						dp[to][j + 1] =  dp[start][j];
					if ( dp[start][j] < s2.size() && s3[i] == s2[dp[start][j]] )
						dp[to][j] = dp[start][j] + 1;
					dp[start][j] = -1;
				}
			}
			// for(int i=0; i<dp[to].size();++i)
			// 	cout << dp[to][i]<<"\t";
			// cout << endl;
		}
		start = (s3.size() )% 2;
		for(int i=0; i<=s1.size(); ++i){
			if( dp[start][i] >= 0)
				return true;
		}
		return false;
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	cout << ss.isInterleave("a", "b","a")<<endl;
	// cout << ss.isInterleave("aabcc", "dbbca","aadbbcbcac")<<endl;
	// cout << ss.isInterleave("aabcc", "dbbca","aadbbbaccc")<<endl;
	cout << "hello world" << endl;
	return 0;
}