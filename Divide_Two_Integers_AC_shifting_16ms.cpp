#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

// https://leetcode.com/problems/divide-two-integers/
class Solution
{
public:

	int divide( int dividend, int divisor )
	{
		//shifting, subtraction,
		//bug free, 0, positive and negative, dividend == int_min, divisor = int_min
		if ( divisor == 0 || ( dividend == INT_MIN && divisor == -1 ) )
			return INT_MAX;
		if ( dividend == INT_MIN && divisor == 1 )
			return INT_MIN;
		if ( divisor == INT_MIN ) {
			if ( dividend == INT_MIN ) return 1;
			else return 0;
		}
		bool isNegative = (dividend < 0) ^ (divisor < 0);
		int addition = 0;
		if ( dividend == INT_MIN ) {
			if ( divisor < 0 )
				dividend += 0 - divisor;
			else
				dividend += divisor;
			addition = 1;
		}
		
		dividend = abs( dividend );
		divisor = abs( divisor );
		long long  quotient  = 0;
		long long tmp_q = 1;
		long long  product = divisor;
		while ( product <= INT_MAX && product < dividend ) {
			product = product << 1;
			// cout << product<<" ";
			tmp_q = tmp_q << 1;
		}
		if ( dividend < product ) {
			product = product >> 1;
			tmp_q = tmp_q >> 1;
		}
		quotient += tmp_q;
		dividend -= product;
		// cout << dividend << ","<<product<< "," << quotient<<endl;
		while ( divisor <= dividend ) {
			while ( dividend < product ) {
				product = product >> 1;
				tmp_q = tmp_q >> 1;
			}
			quotient += tmp_q;
			dividend -= product;
		}
		quotient += addition;
		if ( isNegative )
			quotient = 0 - quotient;
		return quotient;
	}

	void print( int dividend, int divisor )
	{
		cout << divide( dividend, divisor ) << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	cout << INT_MAX << endl;
	cout << INT_MIN << endl;
	// ss.print(INT_MAX-1,1);
	// ss.print(INT_MAX-1,-1);
	// ss.print(INT_MAX,1);
	// ss.print(-INT_MAX,1);
	// ss.print(INT_MIN,1);
	// ss.print( INT_MIN, 2 );
	// ss.print( INT_MIN, -2 );
	// ss.print( INT_MAX, 2 );
	ss.print( -1010369383, -2147483648 );

	return 0;
}