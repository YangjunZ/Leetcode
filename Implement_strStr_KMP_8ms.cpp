#include <iostream>
#include <vector>

using namespace std;


// Implement strStr()

// https://leetcode.com/problems/implement-strstr/

//KMP
//next[n]
//init,next[0]=-1,
//next[j] = -1, (next[j]==next[0] && next[0,...k- 1]!=next[j-k, j-1]) or(next[0..k-1]==next[j-k, j-l] && t[k]==t[j])
//

class Solution
{
public:

	vector<int> prefixString( char *needle )
	{
		int len = 0;
		while ( needle[len] != '\0' ) len++;

		vector<int> pi( len, -1 ); //start with 0..len-1
		pi[0] = -1;

		int k = -1;
		for ( int i = 1; needle[i] != '\0'; i++ ) {
			while ( k >= 0 && needle[k + 1] != needle[i] ) k = pi[k];
			if ( needle[k + 1] == needle[i] ) {
				k++;
			}
			pi[i] = k;
		}
		return pi;
	}

	int strStr( char *haystack, char *needle )
	{
		if( needle[0] == '\0') 
			return 0;
		if( haystack=='\0' && needle[0] != '\0')
			return -1;
		vector<int> pi = prefixString( needle );
		// cout << haystack<<endl;
		for ( int i = 0, k = -1; haystack[i] != '\0'; ++i ) {
			while ( k >= 0 && needle[k + 1] != haystack[i] ) k = pi[k];
			if(needle[k+1] == haystack[i])
				k++;
			// cout << k;
			if (  needle[k+1] == '\0' )
				return i - k ;
		}
		return -1;
	}
	void print( char * haystack ,char *needle )
	{
		// vector<int> pi = prefixString( needle );
		// cout << "Pi:" << endl;
		// for ( int i = 0; i < pi.size(); ++i ) {
		// 	cout << pi[i] << " ";
		// }

		cout << endl << strStr(haystack, needle)<<endl;
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	char needle[]="ababaabc";
	// char needle[] = "ababababca";

	char haystack[] = "bacbababaabcbab";
	// char needle  [] ="";
	// char haystack [] = "";

	Solution ss;
	ss.print( haystack, needle );
	return 0;
}