#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
// https://oj.leetcode.com/problems/surrounded-regions/

class Solution
{
public:
	void bfs( vector<vector<char>> &board, int row, int col )
	{
		board[row][col] = '*';
		deque<pair<int, int> > tmpDq;
		tmpDq.push_back( make_pair( row, col ) );
		pair<int, int> curO;
		// int row, col;
		int rowSize, colSize;
		rowSize = board.size() - 1;
		while ( tmpDq.size() > 0 ) {
			curO = tmpDq.front();
			tmpDq.pop_front();
			row = curO.first;
			col = curO.second;
			colSize = board[row].size() - 1;

			//boundary, x==0; x==board.size()-1;
			//y==0; y==board[x].size()-1;
			// board[]

			if ( col < colSize && board[row][col + 1] == 'O' ) {
				board[row][col + 1] = '*';
				tmpDq.push_back( make_pair( row, col + 1 ) );

			}
			if ( col > 0 && board[row][col - 1] == 'O' ) {
				board[row][col - 1] = '*';
				tmpDq.push_back( make_pair( row, col - 1 ) );
			}
			if ( row < rowSize && board[row + 1][col] == 'O' ) {
				board[row + 1][col] = '*';
				tmpDq.push_back( make_pair( row + 1, col ) );
			}
			if ( row > 0 && board[row - 1][col] == 'O' ) {
				board[row - 1][col] = '*';
				tmpDq.push_back( make_pair( row - 1, col ) );
			}
			
		}

	}


	void solve( vector<vector<char>> &board )
	{
		//find o points which chains each other, then check whether surrounded, remove
		if ( board.size() == 0 )
			return;
		vector<vector<bool> > isVisit( board.size(), vector<bool> ( board[0].size(), false ) );
		vector<pair<int, int> > ostk;
		bool isSurrounded = true;
		for ( int row = 0; row < board.size(); ++row ) {
			if (  board[row][0] == 'O' ) {
				bfs( board,  row, 0 );
			}
			if (  board[row][ board[row].size() - 1] == 'O' ) {
				bfs( board,  row, board[row].size() - 1 );
			}

		}
		for ( int col = 0; col < board[0].size(); ++col ) {
			if (  board[0][ col] == 'O' ) {
				bfs( board,  0, col );
			}
			if (  board[ board.size()-1][ col] == 'O' ) {
				bfs( board,  board.size()-1, col );
			}
		}
		for(int i=0; i<board.size(); ++i){
			for( int j=0; j<board[j].size(); ++j){
				if(board[i][j] =='O')
					board[i][j] = 'X';
			}
		}

		for(int i=0; i<board.size(); ++i){
			for( int j=0; j<board[j].size(); ++j){
				if(board[i][j] =='*')
					board[i][j] = 'O';
			}
		}	

	}

	void print( vector<vector<char>> &board )
	{
		for ( int i = 0; i < board.size(); ++i ) {
			for ( int j = 0; j < board[i].size(); ++j ) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}
};

int main()
{
	vector< vector<char>> board( 4, vector<char>( 4, 'X' ) );
	board[1][1] = 'O';
	board[1][2] = 'O';
	board[2][2] = 'O';
	board[3][1] = 'O';
	Solution ss;
	ss.print( board );
	ss.solve( board );
	cout << endl;
	ss.print( board );
	cout << "hello world" << endl;
	return 0;
}