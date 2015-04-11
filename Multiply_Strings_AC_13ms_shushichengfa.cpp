#include <iostream>

using namespace std;

class Solution
{
public:

	string multiply_core( string num1, string num2 )
	{
		// cout << num1<<endl<<num2<<endl;
		int len = num1.length() + num2.length();
		string res( len , '0' );
		int carry = 0;
		int sum = 0;
		int idx = len - 1;
		for ( int i = num1.length() - 1; 0 <= i; --i ) {
			sum = 0;
			carry = 0;
			idx = len - ( num1.length() - i );
			for ( int j = num2.length()-1; 0 <= j; --j, --idx ) {
				// cout << res[idx];
				sum = carry + ( num1[i] - '0' ) * ( num2[j] - '0' ) + ( res[idx] - '0' );
				res[idx] = sum % 10 + '0';
				carry = sum / 10;
			}

			while ( 0 <= idx && carry != 0 ) {
				sum = res[ idx] - '0' + carry;
				res[ idx] = sum % 10 + '0';
				carry = sum / 10;
				idx --;
			}
			// if ( idx < 0 ) cout << "error" << endl;
		}
		int i=0;
		while(i<res.length() && res[i]=='0') i++;
		return res.substr(i);
	}

	string multiply( string num1, string num2 )
	{
		int i = 0;
		while ( i < num1.length() && num1[i] == '0' ) i++;
		if ( i == num1.length() )
			return "0";
		string num11 = num1.substr( i );
		i = 0;
		while ( i < num2.length() && num2[i] == '0' ) i++;
		if ( i == num2.length() )
			return "0";
		string num22 = num2.substr( i );

		return multiply_core( num11, num22 );
	}
	void run( string num1, string num2 )
	{
		cout << multiply( num1, num2 ) << endl;
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	ss.run( "1234535345342543654654657567546345678678", "1234455324343546569883745073534275403758802134" );
	return 0;
}