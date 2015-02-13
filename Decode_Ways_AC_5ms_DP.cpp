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
		vector<int> count( s.size() + 1, 0 );
		count[0] = 1;
		count[1] = 1;
		for ( int i = 2; i <= s.size(); ++i ) {
			if ( s[i - 1] != '0' ) {
				count[i] += count[i - 1];
			}
			if ( s[i - 2] != '0' && ( ( s[i - 2] - '0' ) * 10 + s[i - 1] - '0' <= 26 ) ) {//10..26
				count[i] += count[i - 2];
			}
			if( s[i-1]=='0' && ((s[i-2] == '0') ||( ( s[i - 2] - '0' ) * 10 + s[i - 1] - '0' > 26 ))) //can't code. "00" [3-9]0
				return 0;
		}
		return count[s.size()];
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	cout << ss.numDecodings("12")<<endl;
	cout << ss.numDecodings("1212")<<endl;
	cout << ss.numDecodings("123020")<<endl;
	cout << "hello world" << endl;
	return 0;
}