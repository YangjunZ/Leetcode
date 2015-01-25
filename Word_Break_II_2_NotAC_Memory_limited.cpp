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
		std::vector< std::vector<string> > vvtr( s.size(), std::vector<string>() );
		string tmpkey = "";
		string tmpstr = "";
		for ( int i = 0; i < s.size(); i++ ) {
			for ( int k = 0; k < vvtr.size() && vvtr[k].size() > 0; ++k ) {
				tmpkey = s.substr( k + 1, i - k );
				if ( dict.find( tmpkey ) != dict.end() ) {
					// cout <<"tmpkey:"<<tmpkey<<endl;
					// break
					for ( int j = 0; j < vvtr[k].size(); ++j ) {
						tmpstr = vvtr[k][j] + ' ' + tmpkey;
						vvtr[i].push_back( tmpstr );
					}
				}
			}
			tmpkey = s.substr( 0, i+1 );
			if ( dict.find( tmpkey ) != dict.end() ) {
				vvtr[i].push_back( tmpstr );
			}
		}


		return vvtr[s.size() - 1];
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