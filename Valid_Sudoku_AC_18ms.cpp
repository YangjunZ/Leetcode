#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool check( int &history, char key )
	{
		if ( key == '.' )
			return true;
		if ( history & 1 << ( key - '0' ) )
			return false;
		history |= 1 << ( key - '0' );
		return true;
	}
	// bool isValidSudoku( vector<vector<char> > &board )
	bool isValidSudoku( string board[] )
	{
		int cols[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		int blocks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		for ( int i = 0; i < 9; ++i ) {
			for ( int j = 0, row = 0; j < 9; ++j ) {
				if ( check( row, board[i][j] ) && check( cols[j], board[i][j] ) && check( blocks[(i / 3) * 3 + j / 3], board[i][j] ) )
					continue;
				return false;
			}
		}
		return true;
	}

};


int main( int argc, char const *argv[] )
{
	string arr[] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
	Solution ss;
	cout << ss.isValidSudoku(arr)<<endl;
	return 0;
}