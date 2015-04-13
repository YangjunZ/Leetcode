#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void permute_core( vector<vector<int>> &res, vector<int> &curStk, vector<bool> &used, vector<int> &num )
	{
		if ( curStk.size() == num.size() ) {
			res.push_back( curStk );
			return;
		}

		for ( int i = 0; i < used.size(); ++i ) {
			if ( !used[i] ) {
				curStk.push_back( num[i] );
				used[i] = true;
				permute_core( res, curStk, used, num );
				used[i] = false;
				curStk.pop_back();
			}
		}
	}

	vector<vector<int> > permute( vector<int> &num )
	{
		vector<vector<int>> res;
		vector<int> curStk;
		vector<bool> used( num.size(), false );

		permute_core( res, curStk, used, num );
		return res;
	}

	void run( vector<int> &num )
	{
		vector<vector<int>> res = permute( num );
		for ( int i = 0; i < res.size(); ++i ) {
			for ( int j = 0; j < res[i].size(); ++j ) {
				cout << res[i][j] << ",";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	int arr[] = {1,2,3,4,5};
	vector<int> num(arr, arr+5);
	Solution ss;
	ss.run(num);
	return 0;
}