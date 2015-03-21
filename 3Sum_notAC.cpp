#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution
{
public:
	vector<vector<int> > threeSum( vector<int> &num )
	{
		unordered_map<int, vector<int>> umap;
		vector<vector<int>> res;
		sort( num.begin(), num.end() );
		int diff_val = 0;
		for ( int i = 0; i < num.size(); ++i ) {
			for ( int j = i + 1; j + 1 < num.size(); ++j ) {
				diff_val = 0 - num[i] - num[j];
				if ( diff_val < num[j + 1] || num[num.size() - 1] < diff_val )
					continue;
				
				if ( binary_search( num.begin() + j + 1, num.end(), diff_val ) ) {
					// cout <<i<<":"<<j<<" "<< num[i]<<","<<num[j]<<endl;
					if ( umap.find( num[i] ) == umap.end() ) {
						vector<int> tmp;
						tmp.push_back( num[j] );
						umap[num[i]] = tmp;
						vector<int> res1;
						res1.push_back( num[i] );
						res1.push_back( num[j] );
						res1.push_back( diff_val );
						res.push_back( res1 );
					} else if ( umap[num[i]][umap[num[i]].size() - 1] < num[j] ) {
						vector<int> res1;
						res1.push_back( num[i] );
						res1.push_back( num[j] );
						res1.push_back( diff_val );
						res.push_back( res1 );
						umap[num[i]].push_back(num[j]);
					}
					// break;
				}
			}
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
	// int arr[] = { -1, 0, 1, 2, -1, -4,6,3,1};
	// int arr[] = {-2,0,1,1,2};
	int arr[] = {0,-4,-1,-4,-2,-3,2};
	vector<int> vv( arr, arr + 7 );
	Solution ss;
	// ss.threeSum( vv );
	ss.print(vv);
	return 0;
}