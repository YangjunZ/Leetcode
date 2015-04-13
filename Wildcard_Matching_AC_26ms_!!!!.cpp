#include <iostream>

using namespace std;

class Solution
{
public:
	// bool isMatch( const char *s, const char *p )
	// {
	// 	//p=*x, check s,&s[1],&s[2]... &s[n] with &p[1]
	// 	//p=?x, check &[s1] with &p[1]
	// 	//p=[a-zA-Z...]x,
	// 	//exit p=*, s='\0'&&p='\0'
	// 	if ( ( p[0] == '*' && p[1] == '\0' ) || ( p[0] == '\0' && s[0] == '\0' ) )
	// 		return true;
	// 	if ( p[0] == '*' ) {
	// 		int j = 0;
	// 		while ( p[j] != '\0' && p[j] == '*' ) j++; //treat multi * as a *
	// 		int i = 0;
	// 		if ( p[j] == '?' ) {
	// 			if ( s[0] == '\0' )
	// 				return false;
	// 			while ( s[i] != '\0' ) {
	// 				if ( isMatch( &s[i], &p[j + 1] ) )
	// 					return true;
	// 				++i;
	// 			}

	// 			return isMatch( &s[i], &p[j + 1] );
	// 		}
	// 		int j_tmp = j;

	// 		while ( s[i] != '\0' && s[i] != p[j] ) i++;
	// 		int i_tmp = i;
	// 		while ( s[i] != '\0' ) {
	// 			while ( s[i] != '\0'  && ( s[i] == p[j] ) ) {
	// 				i++;
	// 				j++;
	// 			}
	// 			if ( isMatch( &s[i], &p[j] ) )
	// 				return true;
	// 			// ++i;
	// 			i_tmp ++;
	// 			i = i_tmp;
	// 			j = j_tmp;
	// 			// cout << i << "," <<j<<endl;
	// 		}
	// 		// return  isMatch( &s[i], &p[j] );
	// 	} else if ( p[0] == '?' && s[0] != '\0' )
	// 		return isMatch( &s[1], &p[1] );
	// 	else if ( s[0] != '\0' ) {
	// 		if ( p[0] == s[0] )
	// 			return isMatch( &s[1], &p[1] );
	// 	}
	// 	return false;
	// }

	bool isMatch2( const char *s, const char *p )
	{
		const char *pres = NULL;
		const char *star = NULL;
		while ( *s ) {
			if ( *p == '?' || *s == *p ) { //match
				p++;
				s++;
				continue;
			}

			//find star
			if ( *p == '*' ) {
				star = p++;
				pres = s;
				continue;
			}
			//star existed, current not match

			if ( star ) {
				s = ++ pres;
				p = star + 1;
				continue;
			}
			return false;
		}
		while(*p == '*') p++;
		return *p == '\0';
	}

	void run( const char *s, const char *p )
	{
		cout << s << " match " << p << endl;
		if ( isMatch2( s, p ) ) {
			cout << "True" << endl;
		} else
			cout << "False" << endl;
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	ss.run( "abcd", "abcd" );
	ss.run( "abcd", "a*****?**???" );
	ss.run( "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b" );
	ss.run( "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb", "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**" );

	ss.run( "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*?*bb" );
	ss.run( "hi", "*?" );
	ss.run( "aa", "*a" );
	ss.run( "ababab", "*abab" );
	ss.run( "abababc", "*abab" );
	ss.run( "aa", "a" );

	return 0;
}