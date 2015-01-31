#include <iostream>

using namespace std;

// Valid Palindrome
// https://oj.leetcode.com/problems/valid-palindrome/
class Solution
{
public:

	bool isPalindrome( string s )
	{
		if ( s == "" )
			return true;
		int i = 0, size = s.size(), j = size - 1;
		bool isEmpty = true;
		char ch, ch2;
		while ( i < size && j >= 0 && i < j ) {
			ch = s[i];
			while ( i < size && !( ( '0' <= ch && ch <= '9' ) || ( 'a' <= ch && ch <= 'z' ) || ( 'A' <= ch && ch <= 'Z' ) ) ) ch = s[++i];

			ch2 = s[j];
			while ( j >= 0 && !( ( '0' <= ch2 && ch2 <= '9' ) || ( 'a' <= ch2 && ch2 <= 'z' ) || ( 'A' <= ch2 && ch2 <= 'Z' ) ) ) ch2 = s[--j];
			

			if ( 'A' <= ch && ch <= 'Z' )
				ch = ch + ( 'a' - 'A' );

			if ( 'A' <= ch2 && ch2 <= 'Z' )
				ch2 = ch2 + ( 'a' - 'A' );
			if ( j <= i ) break;
			isEmpty = false;
		
			if ( ch == ch2 ) {
				i++;
				--j;
			} else
				break;
		}
		if ( i < size && j >= 0 &&  ch ==ch2 ) {
			return true;
		}
		 cout << i << "," << j << endl;
		cout << s[i] << "," << s[j] << endl;
		cout << ch << "," << ch2 << endl;
		if( isEmpty == true) return true;
		return false;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	// string s = "A man, a plan, a canal: Panama";
	string s = "\"Sue,\" Tom smiles, \"Selim smote us.\"";
	// string s = "Aa";
	cout << ss.isPalindrome( s ) << endl;
	cout << "hello word" << endl;
	return 0;
}