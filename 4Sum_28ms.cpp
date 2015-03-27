#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/4sum/

class Solution
{
public:
	vector<vector<int> > fourSum( vector<int> &num, int target )
	{
		vector< vector< int>> res;

		int size = num.size();
		sort( num.begin(), num.end() );
		for ( int i = 0; i < size - 3; ) {
			for ( int j = i + 1; j < size - 2; ) {
				int m = j + 1;
				int n = size - 1;
				while ( m < n ) {
					// int sum = num[i] + num[j] + num[m] + num[n];
					if(num[i] + num[j] + num[m]*2 > target){
						break;
					}
					if(num[i] + num[j] + num[n]*2 < target){
						break;
					}
					while ( m < n && ( num[i] + num[j] + num[m] + num[n] ) < target ) {
						m++;
					}
					while ( m < n && ( num[i] + num[j] + num[m] + num[n] ) > target ) {
						n--;
					}
					if ( m < n && ( num[i] + num[j] + num[m] + num[n] ) == target ) {
						vector<int> tmp;
						tmp.push_back( num[i] );
						tmp.push_back( num[j] );
						tmp.push_back( num[m] );
						tmp.push_back( num[n] );
						res.push_back( tmp );
						m++;
						while ( m < n && num[m] == num[m - 1] ) m++;
						n--;
						while ( m < n && num[n] == num[n + 1] ) n--;
					}
				}
				j++;
				while ( j < size - 2 && num[j] == num[j - 1] ) j++;
			}
			i++;
			while ( i < size - 3 && num[i] == num[i - 1] ) i++;
		}
		return res;
	}

	void print(vector<int> &num, int target){
		vector< vector< int> > res = fourSum(num, target);
		for(int i=0; i<res.size(); ++i){
			for(int j=0; j<res[i].size(); ++j){
				cout << res[i][j]<<",";
			}
			cout <<endl;
		}
		cout <<endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	// int arr[] = {1,0,-1,0,-2,2};
	// vector<int> num(arr, arr+6);

	int arr[] = {1,0,-1,0,-2,2,4,5,6,-10,-3,-4,-2};
	vector<int> num(arr, arr+13);
	Solution ss;
	ss.print(num, 0);
	return 0;
}