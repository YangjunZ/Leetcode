#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Count and Say
// https://leetcode.com/problems/count-and-say/

class Solution
{
public:
	string to_string( int n )
	{
		if ( n == 0 )
			return "0";
		char tmp[15] = {0};
		int base = 14;
		tmp[base--] = '\0';
		while ( n ) {
			tmp[base--] = n % 10 + '0';
			n = n / 10;
		}
		string str( &tmp[base + 1] );
		return str;
	}
	string countAndSay( int n )
	{
		//to vector<char>
		//11 -> 21-> 1211 -> 111221 -> 312211 -> 12112221->1112213211
		//to avoid overflow, all change to char;
		//cnt char,
		string str = "1";
		 // to_string( n );

		int nth = 1;
		while ( nth < n ) {
			int i = 0;
			char ch = str[i++];
			int cnt = 1;
			string nstr;
			while ( i < str.length() ) {
				if ( ch == str[i] ) cnt ++;
				else {
					//append cnt
					//append num
					nstr.append( to_string( cnt ) );
					nstr.append( &str[i - 1], 1 );
					ch = str[i];
					cnt = 1;
				}
				++i;
			}
			nstr.append( to_string( cnt ) );
			nstr.append( to_string( ch - '0' ) );
			// cout << nstr<<endl;
			str = nstr;
			nth ++;
		}
		return str;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	cout << ss.countAndSay( 2 ) << endl;
	return 0;
}