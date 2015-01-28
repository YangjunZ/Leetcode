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

	// vector<string> findPalindrome( string s, int start )
	// {
	//  std::vector<string> v;
	//  int low, up;
	//  for ( int i = start; i < s.size(); ++i ) {
	//      if ( s[i] == s[start] ) {
	//          low = start + 1; up = i - 1;
	//          while ( low < up ) {
	//              if ( s[low] != s[up] )
	//                  break;
	//              low ++ ;
	//              up--;
	//          }
	//          if ( low >= up ) {
	//              v.push_back( s.substr( start, i - start + 1 ) );
	//          }
	//      }
	//  }
	//  return v;
	// }

	vector<int> findPalindrome( string s, int start )
	{
		std::vector<int> v;
		int low, up;
		for ( int i = start; i < s.size(); ++i ) {
			if ( s[i] == s[start] ) {
				low = start + 1; up = i - 1;
				while ( low < up ) {
					if ( s[low] != s[up] )
						break;
					low ++ ;
					up--;
				}
				if ( low >= up ) {
					v.push_back( i );
				}
			}
		}
		return v;
	}

	void dfs( string s, vector< vector<int> > &palindrome, vector< vector<string> > &res, int idx, vector<int> &tmp )
	{
		if ( idx == s.size() ) {
			int start = 0;
			std::vector<string> v;
			for ( int i = 0; i < tmp.size(); ++i ) {
				v.push_back( s.substr( start, tmp[i] - start + 1 ) );
				start = tmp[i] + 1;
			}
			res.push_back( v );
			return;
		}

		for ( int i = 0; i < palindrome[idx].size(); ++i ) {
			tmp.push_back( palindrome[idx][i] );
			dfs( s, palindrome, res, palindrome[idx][i] + 1, tmp );
			tmp.pop_back();
		}
	}



	vector<vector<string> > partition( string s )
	{
		std::vector<std::vector<string> > res;
		std::vector< std::vector<int> > palindrome( s.size(), vector<int> () );
		vector< vector<bool> > mtx( s.size(), vector<bool>( s.size(), false ) );


		for ( int len = 1; len <= s.size(); ++len ) {
			for ( int i = 0; i < s.size() - len + 1; ++i ) {
				if ( len == 1 ) {
					mtx[i][i] = true;
					palindrome[i].push_back( i );
				} else if ( len == 2 && s[i] == s[i + 1] ) {
					mtx[i][i + 1] = true;
					palindrome[i].push_back( i + 1 );
				} else if ( s[i] == s[i + len - 1] && mtx[i + 1][i + len - 2] ) {
					mtx[i][i + len - 1] = true;
					palindrome[i].push_back( i + len - 1 );
				}

			}
		}
		// cout << "he"<<endl;
		std::vector<int> tmp;
		dfs( s, palindrome, res, 0, tmp );
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