#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

#include <cstdlib> //abs
#include <map>
using namespace std;


class Solution
{
public:

	string to_string(long long  num)
	{
		char str[40];
		sprintf( str, "%lld", num); 
		//%lld, output long long
		return str;
	}

	string fractionToDecimal( int numerator0, int denominator0)
	{
		string res = "";
		// -2147483648 = 0x1000 0000 = -2^31, edge num
		long long numerator = numerator0;
		long long denominator = denominator0;

		if ( numerator * denominator < 0) {
			res += '-';
		}
		numerator = abs( numerator);
		denominator = abs( denominator);
		// cout << "input:"<<numerator << " "<<denominator <<endl;
		long long  quotient = 0;
		long long  reminder = 0;
		// cout << res <<endl;
		if ( numerator < denominator) {
			res += "0";
		} else {
			quotient = numerator / denominator;
			res += to_string( quotient);
		}

		numerator = numerator % denominator;
		if ( numerator > 0) {
			res += '.';
			map< long long  ,int> map; 
			// int cnt = 0;
			while( numerator){
				// cout << numerator << ' ';
				if( map.find(numerator) != map.end()){
					//the reminder is the same
					res.insert(map[numerator], 1, '(');
					res += ')';
					break;
				}
				map[numerator] = res.size();
				numerator *= 10;
				res += to_string(numerator / denominator);
				numerator = numerator % denominator;
			}
		}

		// if
		cout << endl;
		cout << res << endl;
		return res;
	}


};

int main()
{
	Solution sl ;

	cout << "hello world" << endl;
	sl.fractionToDecimal(2, 1);
	sl.fractionToDecimal(1, 2);
	sl.fractionToDecimal(1, 16);
	sl.fractionToDecimal(3487445, 2560);
	sl.fractionToDecimal(2, 30);
	sl.fractionToDecimal(1, 3);
	sl.fractionToDecimal(1, 7);
	sl.fractionToDecimal(1, 17);
	sl.fractionToDecimal(7, -12);
	sl.fractionToDecimal(-22, -2);
	sl.fractionToDecimal(1, 214748364);
	sl.fractionToDecimal(-1, -2147483648);
	sl.fractionToDecimal(-2147483648, 1);
	cout  << 2147483648+1<<" "<<-2147483648-1<<endl;
	cout << hex << 2147483648<<" "<<hex<< -2147483648<<" "<<-1<<endl;

	cout <<oct<<int( 0xffffffff)  <<" "<<oct<< 0x7fffffff<<endl;
	// cout << sl.fractionToDecimal(1,3);
	return 0;
}