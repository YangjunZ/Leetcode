#include <iostream>

#include <vector>

using namespace std;
// Generate Parentheses


class Solution
{
public:
	bool isSymmetry( string s )
	{
		int l = 0, u = s.length() - 1;
		while ( l < u ) {
			if ( s[l] == s[u] ) {
				l++;
				u--;
			} else
				return false;
		}
		return true;
	}
	vector<string> generateParenthesis( int n )
	{
		vector<string> arr[2];

		arr[1].push_back( "()" );
		int pre, cur;
		int cnt = 2;
		while ( cnt <= n ) {
			cur = cnt & 1;
			pre = 1 - cur;
			// cout << pre << " "<< cur<<endl;
			for ( int i = 0; i < arr[pre].size(); i++ ) {
				string tmp1 = arr[pre][i] + "()";
				string tmp2 = "()" + arr[pre][i];
				if ( tmp1 != tmp2 ) {
					arr[cur].push_back( tmp1 );
					arr[cur].push_back( tmp2 );
				} else
					arr[cur].push_back( arr[pre][i] + "()" );
				arr[cur].push_back( "(" + arr[pre][i] + ")" );
			}
			arr[pre].clear();
			cnt ++;
		}
		return arr[n & 1];
	}

	void print( int n )
	{
		vector<string> res = generateParenthesis( n );
		for ( int i = 0; i < res.size(); ++i ) {
			cout << res[i] << ",";
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	ss.print( 4 );
	ss.print( 3 );
	ss.print( 2 );
	ss.print( 1 );
	ss.print( 0 );
	return 0;
}