#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/palindrome-partitioning/


class Solution
{
public:
	void print( vector<vector<string> > vv )
	{
		for ( int i = 0; i < vv.size(); ++i ) {
			cout << "[ ";
			for ( int j = 0; j < vv[i].size(); ++j ) {
				// cout <<"\""<<vv[i][j]<<"\",";
				cout << vv[i][j] << ",";
			}
			cout << "]" << endl;
		}
	}



	void dfs( string s, vector< vector<bool> > &mtx, vector< vector<string> > &res, int idx, vector<string>& tmp )
	{
		if ( idx == s.size() ) {
			res.push_back( tmp);
			return;
		}

		for ( int i = idx; i < mtx[idx].size(); ++i ) {
			if ( mtx[idx][i] ) {
				tmp.push_back( s.substr(idx, i-idx +1));
				dfs( s, mtx, res, i + 1, tmp );
				tmp.pop_back();
			}
		}
	}



	vector<vector<string> > partition( string s )
	{
		std::vector<std::vector<string> > res;
		// std::vector< std::vector<int> > palindrome( s.size(), vector<int> () );
		vector< vector<bool> > mtx( s.size(), vector<bool>( s.size(), false ) );


		for ( int len = 1; len <= s.size(); ++len ) {
			for ( int i = 0; i < s.size() - len + 1; ++i ) {
				if ( len == 1 ) {
					mtx[i][i] = true;
					// palindrome[i].push_back( i );
				} else if ( len == 2 && s[i] == s[i + 1] ) {
					mtx[i][i + 1] = true;
					// palindrome[i].push_back( i + 1 );
				} else if ( s[i] == s[i + len - 1] && mtx[i + 1][i + len - 2] ) {
					mtx[i][i + len - 1] = true;
					// palindrome[i].push_back( i + len - 1 );
				}

			}
		}
// cout << "he"<<endl;
		std::vector<string> tmp;
		dfs( s, mtx, res, 0, tmp );
		return res;
	}


};

int main()
{
	string s = "abaacddc";
	// string s = "aab";
	Solution ss;
	// ss.partition( s );
	ss.print( ss.partition( s ) );
	cout << "hello world" << endl;
	return 0;
}