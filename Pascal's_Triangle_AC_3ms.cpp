#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/pascals-triangle/

class Solution
{
public:
	vector<vector<int> > generate( int numRows )
	{
		vector< vector< int>> vv;
		if ( numRows == 0 ) {
			return vv;
		}
		vv.push_back( vector<int> ( 1, 1 ) );
		// if ( numRows == 1 ) {
		// 	return vv;
		// }
		for ( int i = 1; i < numRows; i++ ) {
			vector<int> tmp ;
			tmp.push_back( 1 );
			for ( int j = 1; j < i; j++ )
				tmp.push_back( vv[i - 1][j - 1] + vv[i - 1][j] );
			tmp.push_back( 1 );
			vv.push_back(tmp);
		}
		return vv;
	}

	void print( vector< vector<int>> vv){
		cout <<"[";
		for(int i=0; i<vv.size(); ++i){
			cout <<"[";
			for(int j=0; j<vv[i].size(); ++j)
				cout << vv[i][j]<<",";
			cout <<"]"<<endl;
		}
		cout <<"]"<<endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	ss.print( ss.generate(1));
	ss.print( ss.generate(2));
	ss.print( ss.generate(5));
	return 0;
}