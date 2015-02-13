#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/decode-ways/


// bug free: digit[0-9]
// s[i] != 0, count[i+1] = count[i]
// s[i-1,i] <= 26, count[i+1] +=count[i-1]
// s[0] = '0', can't decode. "00", can't decode
// count[i] store the number of decode ways with encode string s[0, i)

class Solution
{
public:
	int numDecodings( string s )
	{
		if ( s == "" || s[0] == '0' )
			return 0;
		int cur = 1, pre = 1;
		//cur, the number of decode ways with [0,i],
		//pre, the number of decode ways with [0,i-1]

		for ( int i = 1; i < s.size(); ++i ) {
			if ( s[i] == '0' ) //when s[i]=='0', if this digit only can decode with himself, then this string can't be decoded
				cur = 0;

			if ( s[i - 1] == '1' || ( s[i - 1] == '2' && s[i] <= '6' ) ) {
				cur = cur + pre;// count [0,i-1] + count[0, i-2]
				pre = cur - pre;// store count [0, i-1]
			} else {// the last digit only can decode with himself
				pre = cur;
			}

			if ( pre  == 0 && pre == cur )//can't be decode
				return 0;
		}
		return  cur;
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	cout << ss.numDecodings( "12" ) << endl;
	cout << ss.numDecodings( "1212" ) << endl;
	cout << ss.numDecodings( "123020" ) << endl;
	cout << "hello world" << endl;
	return 0;
}