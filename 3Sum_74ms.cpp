#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution
{
public:

	bool findKey( vector<int> &num, vector<vector<int> > &res, int i, int j )
	{
		int diff_val = 0 - num[i] - num[j];
		if ( binary_search( num.begin() + i + 1, num.begin() + j, diff_val ) ) {
			vector<int> res1;
			res1.push_back( num[i] );
			res1.push_back( diff_val );
			res1.push_back( num[j] );
			res.push_back( res1 );
			return true;
		}
		return false;
	}

	vector<vector<int> > threeSum( vector<int> &num )
	{
		vector<vector<int>> res;
		sort( num.begin(), num.end() );
		//check 0,n,
		//check 0,n-1,n-2,.. until success
		//check n,1,2,3, .. until success
		//check 1, n-1

		int diff_val = 0;
		int i = 0;
		int j = num.size() - 1;
		int tmpi, tmpj;
		while ( i + 1 < j ) {
			findKey( num, res, i, j );
			tmpi = i + 1;
			while ( tmpi + 1 < j && num[tmpi] == num[tmpi - 1] )
				tmpi++;
			while ( tmpi + 1 < j ) {
				if ( 0 - num[tmpi] - num[j] < num[tmpi] )
					break;
				findKey( num, res, tmpi, j );
				tmpi++;
				while ( tmpi + 1 < j && num[tmpi] == num[tmpi - 1] )
					tmpi++;
			}
			tmpj = j - 1;
			while ( i + 1 < tmpj && num[tmpj] == num[tmpj + 1] )
				tmpj--;
			while ( i + 1 < tmpj ) {
				if ( num[tmpj] < 0 - num[i] - num[tmpj] )
					break;
				findKey( num, res, i, tmpj );
				tmpj--;
				while ( i + 1 < tmpj && num[tmpj] == num[tmpj + 1] )
					tmpj--;
			}
			i++;
			while ( i + 1 < j && num[i] == num[i - 1] )
				i++;
			j--;
			while ( i + 1 < j && num[j] == num[j + 1] )
				j--;
		}
		return res;
	}

	void print( vector<int> &num )
	{
		vector<vector<int> > res = threeSum( num );
		for ( int i = 0; i < res.size(); i++ ) {
			cout << res[i][0] << "," << res[i][1] << "," << res[i][2] << endl;
		}
	}
};

int main( int argc, char const *argv[] )
{
	// int arr[] = { -1, 0, 1, 2, -1, -4,6,3,1};//8
	// int arr[] = {-2,0,1,1,2};
	// int arr[] = {0, -4, -1, -4, -2, -3, 2};
	// int arr[] = {7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6}; //109
	// int arr []={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};//15
	int arr[] = { -1, 0, 1, 2, -1, 2, -2, -2, 1}; //9
	vector<int> vv( arr, arr + 9 );
	Solution ss;
	// ss.threeSum( vv );
	ss.print( vv );
	return 0;
}