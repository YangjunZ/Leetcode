#include <iostream>

#include <vector>

using namespace std;

class Solution
{
public:
	void getString( string digits, char *chs, int idx, vector<string> map, vector<string> &res )
	{
		// cout << digits[idx]<<",";
		if ( idx == digits.length() ) {
			chs[idx] = '\0';
			// cout << chs<<endl;
			string tmp( chs, &chs[idx] );
			res.push_back( chs );
			return;
		}
		int cnt = 0;
		int didx = digits[idx] - '0';
		if(didx < 0 || didx > 9)
			return;
		while ( cnt < map[didx].length() ) {
			chs[idx] = map[didx][cnt];
			getString( digits, chs, idx + 1, map, res );
			cnt++;
		}
	}

	vector<string> letterCombinations( string digits )
	{
		//stack[i] record the position of digits[lenCnt]
		vector<string> res;
		if(digits=="")
			return res;
		vector<string> map;
		map.push_back( " " );
		map.push_back( "" );
		map.push_back( "abc" );
		map.push_back( "def" );
		map.push_back( "ghi" );
		map.push_back( "jkl" );
		map.push_back( "mno" );
		map.push_back( "pqrs" );
		map.push_back( "tuv" );
		map.push_back( "wxyz" );
		map.push_back( "+" );
		map.push_back( "#" );

		

		char *chs = new char[digits.size() + 1];
		getString( digits, chs, 0, map, res );
		return res;
	}

	void print( string digits )
	{
		vector<string> res = letterCombinations( digits );
		for ( int i = 0; i < res.size(); i++ ) {
			cout << res[i] << ",";
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	// ss.print( "23034" );
	ss.print( "2" );

	return 0;
}