#include <iostream>

using namespace std;
// ZigZag Conversion

class Solution
{
public:
	string convert( string s, int nRows )
	{
		if(nRows ==1)
			return s;
		//interval, low((nRows+1)/2)*nRows-(0+low((nRows-1)/2))*(low((nRows+1)/2))
		int colMax = ( nRows + 1 ) / 2;
		// int interval = (nRows+1)/2*nRows;
		// interval = interval - ((nRows-1)/2)*((nRows+1)/2);
		int interval = colMax * nRows - ( ( nRows - 1 ) / 2 ) * colMax;
		int len = s.size();
		string res( len, '\0' );
		int index,  cnt;
		cnt = 0;
		for ( int i = 1; i <= nRows; ++i ) {
			if ( i <= ( nRows + 1 ) / 2 ) {
				colMax = i;
			} else {
				colMax = nRows - i;
			}
			for ( int base = 0; base <= len; base += interval ) {
				//i<= (nRows+1)/2
				index = base + i - 1;
				if ( len <= index ) {
					continue;
				}
				res[cnt] = s[index];
				cnt++;
				for ( int j = 1; j < colMax ; ++j ) {
					index += nRows - j * 2 + 1;
					if ( len <= index )
						break;
					res[cnt] = s[index];
					cnt++;
				}
			}
		}
		return res;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	string s="PAYPALISHIRING";

	Solution ss;
	cout<<ss.convert(s,3)<<endl;
	cout<<ss.convert(s,2)<<endl;

	// cout << str << endl;
	// str[1] = 'a';
	// cout << str << endl;
	// string str2( 8, 'a' );
	// cout << str2 << endl;
	return 0;
}