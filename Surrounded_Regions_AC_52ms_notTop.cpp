#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
// https://oj.leetcode.com/problems/surrounded-regions/

class Solution
{
public:
	void bfs( vector<vector<char>> &board, vector<vector<bool> > &isVisit, int row, int col)
	{
		// int rowSize = board.size();
		deque<pair<int, int> > tmpDq;
		vector<pair<int, int> > ostk;
		ostk.push_back( make_pair(row, col));
		tmpDq.push_back( ostk.front() );
		bool isSurrounded = true;
		pair<int, int> curO;
		// int row, col;
		int rowSize, colSize;
		rowSize = board.size() - 1;
				// cout << "s,row"<<row<<",col"<<col<<endl;
		while ( tmpDq.size() > 0 ) {
			curO = tmpDq.front();
			tmpDq.pop_front();
			row = curO.first;
			col = curO.second;
			colSize = board[row].size() - 1;

			//boundary, x==0; x==board.size()-1;
			//y==0; y==board[x].size()-1;
			// board[]

			if ( col < colSize && isVisit[row][col + 1] == false && board[row][col + 1] == 'O' ) {
				isVisit[row][col + 1] = true;
				tmpDq.push_back( make_pair( row, col + 1 ) );
				ostk.push_back( make_pair( row, col + 1 ) );
			}
			if ( col > 0 && isVisit[row][col - 1] == false && board[row][col - 1] == 'O' ) {
				isVisit[row][col - 1] = true;
				tmpDq.push_back( make_pair( row, col - 1 ) );
				ostk.push_back( make_pair( row, col - 1 ) );
			}
			if ( row < rowSize && isVisit[row + 1][col] == false && board[row + 1][col] == 'O' ) {
				isVisit[row + 1][col] = true;
				tmpDq.push_back( make_pair( row + 1, col ) );
				ostk.push_back( make_pair( row + 1, col ) );
			}
			if ( row > 0 && isVisit[row - 1][col] == false && board[row - 1][col] == 'O' ) {
				isVisit[row - 1][col] = true;
				tmpDq.push_back( make_pair( row - 1, col ) );
				ostk.push_back( make_pair( row - 1, col ) );
			}
			if ( row == 0 || row == rowSize || col == 0 || col == colSize ) {
				// cout << "row"<<row<<",col"<<col<<endl<<endl;
				isSurrounded = false;
			}
		}

		if ( isSurrounded ) {
			while ( ostk.size() > 0 ) {
				curO = ostk.back();
				ostk.pop_back();
				board[curO.first][curO.second] = 'X';
			}
		}
	}


	void solve( vector<vector<char>> &board )
	{
		//find o points which chains each other, then check whether surrounded, remove
		if(board.size() == 0)
            return;
		vector<vector<bool> > isVisit( board.size(), vector<bool> ( board[0].size(), false ) );
		vector<pair<int, int> > ostk;
		// bool isSurrounded = true;
		for ( int i = 0; i < board.size(); ++i ) {
			for ( int j = 0; j < board[i].size(); ++j ) {
				if ( isVisit[i][j] == false && board[i][j] == 'O' ) {
					// findchain() and sign the 'O'
					// ostk.push_back( make_pair( i, j ) );
					bfs( board, isVisit, i, j);
					// isSurrounded = true;
				}
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