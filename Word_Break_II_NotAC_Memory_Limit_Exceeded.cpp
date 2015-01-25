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
	vector<string> wordBreak( string s, unordered_set<string> &dict )
	{

		// int **mtx = new int *[s.size() + 1];
		// for ( int i = 0; i <= s.size(); ++i ) {
		//  mtx[i] = new int[s.size() + 1];
		//  for ( int j = 0; j <= s.size(); j++ )
		//      mtx[i][j] = 0;
		// }

		std::vector< std::vector<string> > vvtr;
		for ( int i = 0; i < s.size(); i++ ) {
			std::vector<string> v;
			vvtr.push_back( v );
		}
		unordered_set<int> split;
		split.insert( -1 );
		string tmpkey = "";
		string tmpstr = "";
		for ( int i = 0; i < s.size(); i++ ) {
			for ( auto itr = split.begin(); itr != split.end(); ++itr ) {
				tmpkey = s.substr( *itr + 1, i - *itr );
				if ( dict.find( tmpkey ) != dict.end() ) {
					// cout <<"tmpkey:"<<tmpkey<<endl;
					split.insert( i );
					if ( *itr == -1 ) {
						vvtr[i].push_back( tmpkey );
					} else {

						// break
						for ( int j = 0; j < vvtr[*itr].size(); ++j ) {
							tmpstr = vvtr[*itr][j] + ' ' + tmpkey;
							vvtr[i].push_back( tmpstr );
						}
					}
				}
			}
		}

		return vvtr[s.size() - 1];
	}

	void test( void )
	{
		// unordered_set<string> dict = {"leet", "code"};
		// string s = "leetcode";
		unordered_set<string> dict = {"a","aa", "b"};
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