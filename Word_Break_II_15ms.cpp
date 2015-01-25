#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/word-break-ii/
// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].

// A solution is ["cats and dog", "cat sand dog"].




class Solution
{
public:
	std::vector<string> getSentence( string s, bool **mtx, int idx )
	{
		std::vector<string> vstr;
		string tmpstr = "";
		std::vector<string> tmpv;
		for ( int i = 0; i <= idx; ++i ) {
			if ( mtx[idx][i] ) {
				if ( i == idx )
					vstr.push_back( s.substr( 0, idx + 1 ) );
				else {
					tmpstr = s.substr( i + 1, idx - i );
					tmpv = getSentence( s, mtx, i );
					for ( int j = 0; j < tmpv.size(); j++ ) {
						vstr.push_back( tmpv[j] + ' ' + tmpstr );
					}
				}
			}
		}
		return vstr;
	}
	vector<string> wordBreak( string s, unordered_set<string> &dict )
	{
		bool **mtx = new bool*[s.size()];
		for ( int i = 0; i < s.size(); i++ ) {
			mtx[i] = new bool[s.size()];
			for ( int j = 0; j < s.size(); ++j ) {
				mtx[i][j] = false;
			}
		}
		unordered_set<int> split;
		split.insert( -1 );
		string tmpkey = "";
		string tmpstr = "";
		
		for ( int i = 0; i < s.size(); i++ ) {
			for ( auto itr = split.begin(); itr != split.end(); ++itr ) {
				tmpkey = s.substr( *itr + 1, i - *itr );
				if ( dict.find( tmpkey ) != dict.end() ) {
					// cout << "tmpkey:" << tmpkey << endl;
					split.insert( i );
					if ( *itr == -1 ) {
						mtx[i][i] = true;
					} else {
						mtx[i][*itr] = true;
					}
				}
			}
		}
		std::vector<string> vstr;
		std::vector<string> tmpv;
		for ( int i = 0; i < s.size(); ++i ) {
			if ( mtx[s.size() - 1][i] ) {
				// cout << "idx:" << i << endl;
				if ( i == s.size() - 1 ) {
					vstr.push_back( s.substr( 0, i + 1 ) );
				} else {
					tmpkey = s.substr( i + 1, s.size() - 1 - i );
					tmpv = getSentence( s, mtx, i );
					for ( int j = 0; j < tmpv.size(); ++j ) {
						vstr.push_back( tmpv[j] + ' ' + tmpkey );
					}
				}
			}
		}
		return vstr;
	}

	void test( void )
	{
		// unordered_set<string> dict = {"leet", "code"};
		// string s = "leetcode";

		unordered_set<string> dict = {"a", "aa", "b"};
		string s = "abaaaa";

		auto vv = wordBreak( s, dict );
		if ( vv.size() > 0 ) {
			for ( int i = 0; i < vv.size(); ++i )
				cout << vv[i] << endl;

		} else {
			cout << "false" << endl;
		}
	}
};


int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}