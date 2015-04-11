#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


class Solution
{
public:
	// void print(vector<vector<char>> &board);
	
	int cols[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int blocks[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int rows [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	bool check( vector<vector<char>> &board, int r, int c )
	{
		int key = 1 << ( board[r][c] - '0' );
		if ( ( rows[r] & key ) || ( cols[c] & key ) || ( blocks[( r / 3 ) * 3 + c / 3] & key ) ) {
			return false;
		} else {
			rows[r] |= key;
			cols[c] |= key;
			blocks[( r / 3 ) * 3 + c / 3] |= key;
			return true;
		}

	}

	void restore( vector<vector<char>> &board, int r, int c )
	{
		int key = ~( 1 << ( board[r][c] - '0' ) );
		rows[r] &= key;
		cols[c] &= key;
		blocks[( r / 3 ) * 3 + c / 3] &= key;
	}

	static void adjust( int &r, int &c, bool &finished )
	{
		if ( c == 9 ) {
			c = 0;
			r++;
		}
		if ( r == 9) {
			finished = true;
			return ;
		}
	}

	void solve( vector<vector<char>> &board, int r, int c, bool &finished )
	{
		adjust( r, c, finished );
		// cout << r << "," << c << endl;
		// print( board );
		while ( !finished && board[r][c] != '.' ) adjust( r, ++c, finished );
		if ( !finished && board[r][c] == '.' ) {
			for ( int i = 1; i <= 9; ++i ) {
				board[r][c] = i + '0';
				if ( check( board, r, c ) ) {
					solve( board, r, c + 1, finished );
					if ( finished )
						return;
					restore( board, r, c );
				}
			}
			board[r][c] = '.';
		}
	}

	void solveSudoku( vector<vector<char> > &board )
	{
		for ( int r = 0; r < 9; ++r ) {
			for ( int c = 0; c < 9; ++c ) {
				if ( board[r][c] != '.' )
					if(check( board, r, c ) == false) 
						return;
			}
		}
		bool finished = false;
		solve( board, 0, 0, finished );
		// cout <<"finished:"<< finished<<endl;
	}

	void print( vector<vector<char>> &board )
	{
		for ( int i = 0; i < 9; ++i ) {
			for ( int j = 0; j < 9; ++j )
				cout << board[i][j];
			cout << endl;
		}
		cout << endl;
	}

	void run( vector<vector<char>> &board )
	{
		print( board );

		solveSudoku( board );

		print( board );
	}
};


int main( int argc, char const *argv[] )
{
	// string arr[] = {".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........"};
	// vector<vector<
	string arr[] = {"..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.."};

	vector<vector<char>> board;
	for ( int i = 0; i < 9; ++i ) {
		vector<char> vv( &arr[i][0], &arr[i][0] + 9 );
		board.push_back( vv );
	}
	Solution ss;
	ss.run( board );

	// bitset<32> tmp(1<<9);
	// bitset<32> tmp2(3 &(~(1<<1)));
	// cout << tmp<<","<<tmp2<<endl;
	return 0;
}