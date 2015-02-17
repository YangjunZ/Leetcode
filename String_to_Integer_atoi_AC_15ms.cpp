#include <iostream>
#include <climits>
using namespace std;

// https://oj.leetcode.com/problems/string-to-integer-atoi/


class Solution
{
public:
	int atoi( string str )
	{
		if ( str.size() == 0 )
			return 0;
		int isNegative = false;
		int idx = 0;
		long long res = 0;
		while ( str[idx] == ' ' ) idx++;
		if ( str[idx] == '-' ) {
			idx ++;
			isNegative = true;
		} else if ( str[idx] == '+' ) {
			idx++;
		}

		while ( idx < str.size() && ( '0' <= str[idx] && str[idx] <= '9' ) ) {
			res = res * 10 + str[idx++] - '0';
			if(INT_MAX < res -1)
				break;
		}
		// if ( idx < str.size() )
		//  return 0;
		if (  isNegative && INT_MAX < res - 1 )
			return INT_MIN;
		if ( isNegative == false && INT_MAX < res )
			return INT_MAX;
		if ( isNegative )
			res = -res;
		return res;
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	cout << ss.atoi( "122344" ) << endl;
	cout << ss.atoi( "-122344" ) << endl;
	cout << ss.atoi( "-00122344" ) << endl;
	cout << ss.atoi( "-2147483648" ) << endl;
	cout << ss.atoi( "2147483647" ) << endl;
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	return 0;
}