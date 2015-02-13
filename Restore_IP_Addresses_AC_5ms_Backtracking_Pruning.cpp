#include <iostream>
#include <vector>
#include <string>

using namespace std;
// https://oj.leetcode.com/problems/restore-ip-addresses/

int stoi( string str ) //no negative
{
	int tmp = 0;
	for ( int i = 0; i < str.size(); ++i ) {
		tmp = tmp * 10 + str[i] - '0';
	}
	return tmp;
}

class Solution
{
public:
	//soldier = {a1, a2, a3}, s[0,a1).s[a1,a2).s[a2, a3).s[a3,s.size()) is a ip address
	bool checkZero( string str )
	{
		if ( str[0] == '0' && str.size() > 1 )
			return false;
		return true;
	}
	void backtracking( string s, vector<int> &soldier, vector<string> &res )
	{
		// s.size()/(4-soldier.size())
		// for(int i=0; i<soldier.size(); ++i){
		//  cout << soldier[i]<<",";
		// }
		// cout <<endl;
		if ( soldier.size() == 4 ) {
			//generate ip
			if ( s.size() - soldier.back() > 3 ) return; //pruning

			string str0, str1, str2, str3;
			str0 = s.substr( soldier[0], soldier[1] );
			str1 = s.substr( soldier[1], soldier[2] - soldier[1] );
			str2 = s.substr( soldier[2], soldier[3] - soldier[2] );
			str3 = s.substr( soldier[3], s.size() - soldier[3] );
			if ( checkZero( str0 ) && checkZero( str1 ) && checkZero( str2 ) && checkZero( str3 ) ) {
				// string tmp = str0 + '.' + str1 + '.' + str2 + '.' + str3;
				// cout << tmp << endl;
				if ( stoi( str3 ) < 256 && stoi( str2 ) < 256 && stoi( str1 ) < 256 && stoi( str0 ) < 256 ) {
					string tmp = str0 + '.' + str1 + '.' + str2 + '.' + str3;
					cout << tmp << endl;
					res.push_back( tmp );
				}
			}
			return;
		}

		if ( soldier.back() + 1 <= s.size() && \
		     s.size() - soldier.back() >= ( 4 - soldier.size() + 1 ) && \
		     s.size() - soldier.back() <= ( 4 - soldier.size() + 1 ) * 3 ) {
			soldier.push_back( soldier.back() + 1 );
			backtracking( s, soldier, res );
			soldier.pop_back();
		}
		if ( soldier.back() + 2 <= s.size() && \
		     s.size() - soldier.back() - 1 >= ( 4 - soldier.size() + 1 ) && \
		     s.size() - soldier.back() - 1 <= ( 4 - soldier.size() + 1 ) * 3 ) {
			soldier.push_back( soldier.back() + 2 );
			backtracking( s, soldier, res );
			soldier.pop_back();
		}
		if ( soldier.back() + 3 <= s.size() && \
		     s.size() - soldier.back() - 2 >= ( 4 - soldier.size() + 1 ) && \
		     s.size() - soldier.back() - 2 <= ( 4 - soldier.size() + 1 ) * 3 ) {
			soldier.push_back( soldier.back() + 3 );
			backtracking( s, soldier, res );
			soldier.pop_back();
		}
	}

	vector<string> restoreIpAddresses( string s )
	{
		vector<string> res;
		vector<int> soldier;
		soldier.push_back( 0 );
		backtracking( s, soldier, res );
		return res;
	}
};

void print( vector<string> vct )
{
	for ( int i = 0; i < vct.size(); ++i )
		cout << vct[i] << endl;
}
int main( int argc, char const *argv[] )
{
	Solution ss;
	// print( ss.restoreIpAddresses( "25525511135" ) );
	// print( ss.restoreIpAddresses( "0.0.0.0" ) );
	ss.restoreIpAddresses( "0000" );
	ss.restoreIpAddresses( "010010" );
	// ss.restoreIpAddresses( "25525511135" )
	cout << "hello world" << endl;
	return 0;
}