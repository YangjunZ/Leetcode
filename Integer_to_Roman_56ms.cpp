#include <iostream>

using namespace std;

class Solution
{
public:

	string change( int digit, string one, string five, string ten )
	{
		string res;
		if ( digit != 0 ) { //k
			if ( digit < 4 ) {
				while ( digit-- ) {
					res +=  one;
				}
			} else if ( digit == 4 ) {
				res += one + five;
			} else if ( digit == 9 ) {
				res += one + ten;
			} else {
				res += five;
				digit -= 5;
				while ( digit -- ) {
					res += one;
				}
			}
		}
		return res;
	}

	string intToRoman( int num )
	{
		//digit 4,5,9
		if ( num == 0 || num > 3999 )
			return "";
		string res = "";
		int digit = num / 1000;
		res += change( digit, "M", "", "" );
		digit = num / 100 % 10;
		res += change( digit, "C", "D", "M" );
		digit = num / 10 % 10;
		res += change( digit, "X", "L", "C" );
		digit = num % 10;
		res += change( digit, "I", "V", "X" );
		return res;
	}
	void print(int num){
		cout <<num<<":"<< intToRoman(num)<<endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	ss.print(123);
	ss.print(1457);
	ss.print(3000);
	ss.print(0);
	ss.print(199);
	ss.print(3999);
	ss.print(30);
	ss.print(10000);
	return 0;
}