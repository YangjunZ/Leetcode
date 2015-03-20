#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
	int getNum( char ch )
	{
		switch ( ch ) {
		case 'M': return 1000;
		case 'D': return 500;
		case 'C': return 100;
		case 'L': return 50;
		case 'X': return 10;
		case 'V': return 5;
		case 'I': return 1;
		default: return -1;
		}
	}
	int romanToInt( string s )
	{
		int res = 0;
		int cnt = 0;
		int pre = INT_MAX;
		int cur = 0;
		while ( cnt < s.length() ) {
			cur = getNum( s[cnt] );
			if ( cur == 0 )
				return -1;
			if ( pre < cur ) {
				res += cur - pre - pre;
				pre = cur;
			} else {
				res += cur;
				pre = cur;
			}
			cnt ++;
		}
		return res;
	}

	void print(string s){
		cout << s << ":"<<romanToInt(s)<<endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	ss.print("XXXIV");
	ss.print("MCXXXIV");
	ss.print("MMMCMXCIX");
	return 0;
}