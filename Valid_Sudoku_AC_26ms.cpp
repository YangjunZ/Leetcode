#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool isValidSudoku( vector<vector<char> > &board )
	{
		vector<bool> chk( 10, false );
		int key;
		for ( int i = 0; i < board.size(); ++i ) {
			for ( int j = 0; j < 10; ++j ) {
				chk[j] = false;
			}
			for ( int j = 0; j < board[i].size(); ++j ) {
				key = board[i][j];
				if ( key == '.' ) continue;
				else key = key - '0';
				if ( chk[key] )
					return false;
				chk[key] = true;
			}
		}
		for ( int i = 0; i < board[0].size(); ++i ) {
			for ( int j = 0; j < 10; ++j ) {
				chk[j] = false;
			}
			for ( int j = 0; j < board.size(); ++j ) {
				key = board[j][i];
				if ( key == '.' ) continue;
				else key = key - '0';
				if ( chk[key] )
					return false;
				chk[key] = true;
			}
		}
		for ( int basei = 0; basei < board.size(); basei += 3 ) {
			for ( int basej = 0; basej < board[basei].size(); basej += 3 ) {
				for ( int i = 0; i < 10; ++i )
					chk[i] = false;
				for ( int i = 0; i < 3; ++i ) {
					for ( int j = 0; j < 3; ++j ) {
						key = board[basei + i][basej + j];
						if ( key == '.' ) continue;
						else key = key - '0';
						if ( chk[key] )
							return false;
						chk[key]  = true;
					}
				}
			}
		}
		return true;
	}

};


int main( int argc, char const *argv[] )
{
	return 0;
}