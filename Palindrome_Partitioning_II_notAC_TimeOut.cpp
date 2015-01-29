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



	void dfs( string s, vector< vector<int> > &palindrome, int &min_cut, int idx, int cut_cnt )
	{
		if ( idx == s.size() ) {
			if ( cut_cnt - 1 < min_cut )
				min_cut = cut_cnt - 1;
			return;
		}

		if ( min_cut <= cut_cnt )
			return;
		// cout << "idx:" << idx << "cut_cnt:" << cut_cnt << endl;
		for ( int i = 0; i < palindrome[idx].size(); ++i ) {
			dfs( s, palindrome, min_cut, palindrome[idx][i] + 1, cut_cnt + 1 );
		}
	}

	int minCut( string s )
	{
		std::vector< std::vector<int> > palindrome( s.size(), vector<int> () );
		vector< vector<int> > mtx( s.size(), vector<int>( s.size(), s.size() ) );
		// int min_cut = s.size() - 1;
		cout << s.size() << endl;
		for ( int len = 1; len <= s.size(); ++len ) {
			for ( int i = 0; i < s.size() - len + 1; ++i ) {
				if ( len == 1 ) {
					mtx[i][i] = 0;
					palindrome[i].push_back( i );

				} else if ( len == 2 && s[i] == s[i + 1] ) {
					mtx[i][i + 1] = 0;
					palindrome[i].push_back( i + 1 );
				} else if ( s[i] == s[i + len - 1] && mtx[i + 1][i + len - 2] == 0 ) {
					mtx[i][i + len - 1] = 0;
					palindrome[i].push_back( i + len - 1 );
				} else { //pingjie
					// cout <<"he"<<endl;
					// for ( int k = i; k < i + len - 1; ++k ) {
					//  if ( mtx[i][i + len - 1] == 1 ) {
					//      break;
					//  }
					//  if ( mtx[i][k] + mtx[k + 1][i + len - 1] + 1 < mtx[i][i + len - 1] ) {
					//      mtx[i][i + len - 1] = mtx[i][k] + mtx[k + 1][i + len - 1] + 1;

					//  }

					// }
					for ( int k = palindrome[i].size()-1; k >=0; --k ) {
						if(mtx[i][i + len - 1] <= 1) break;
						if ( mtx[i][ palindrome[i][k] ] + mtx[palindrome[i][k] + 1][i + len - 1] + 1 < mtx[i][i + len - 1] ) {
							mtx[i][i + len - 1] = mtx[i][ palindrome[i][k] ] + mtx[palindrome[i][k] + 1][i + len - 1] + 1;
						}
					}
					if(mtx[i][i + len - 1] < s.size())
						palindrome[i].push_back(i+len-1);

				}

			}
		}
		// for(int i=0; i<s.size(); ++i){
		//  for(int j=0; j<s.size(); ++j)
		//      cout << mtx[i][j]<<" ";
		// cout <<endl;
		// }
		return mtx[0][s.size() - 1];
	}

};

int main()
{
	// string s = "abaacddc";
	// string s = "aab";
	string s = "apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
	// string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	// string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	Solution ss;
	// ss.partition( s );
	cout << ss.minCut( s ) << endl;
	cout << "hello world" << endl;
	return 0;
}