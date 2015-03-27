#include <iostream>
#include <vector>

using namespace std;


// Valid Parentheses


// https://leetcode.com/problems/valid-parentheses/
class Solution
{
public:
	bool isValid( string s )
	{
		vector<char> stack;
		int cnt = 0;
		while ( cnt < s.length() ) {
			if ( s[cnt] == '(' || s[cnt] == '[' || s[cnt] == '{' ) {
				stack.push_back( s[cnt] );
			} else {
				if ( stack.size() > 0  && ((s[cnt]==')' && stack.back()=='(') || (s[cnt]==']' && stack.back()=='[') || (s[cnt]=='}' && stack.back()=='{'))){
					stack.pop_back();
				} else {
					return false;
				}
			}
			cnt ++;
		}
		if ( stack.size() == 0 ) {
			return true;
		}
		return false;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	string s="{[({}[]{([])})]}";
	Solution ss;
	cout << ss.isValid(s)<<endl;
	return 0;
}