#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void solve( vector<int> &candidates, int idx, int target, int sum, vector<int> &stack, vector<vector<int>> &res )
	{
		if ( candidates.size() <= idx ) return;
		if ( sum + candidates[idx] > target ) return;
		
		solve( candidates, idx + 1, target, sum, stack, res );
		// cout << "xxx"<<endl;
		int factor = target / candidates[idx];
		int i = 1;
		while ( i <= factor ) {
			// cout << "xxx"<<i<<endl;
			sum += candidates[idx];
			stack.push_back( candidates[idx] );
			if ( sum == target ) {
				res.push_back(stack );
			} else if ( sum < target ) {
				// stack.push_back( candidates[idx] );
				solve( candidates, idx + 1, target, sum, stack, res );
			} else
				break;
			i++;
		}

		while ( stack.size()  && stack.back() == candidates[idx] ) {
			stack.pop_back();
		}
		
	}
	vector<vector<int> > combinationSum( vector<int> &candidates, int target )
	{
		//force
		// ensure first ,recursion to find a solution
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int > stack;
		solve( candidates, 0, target, 0, stack, res );
		return res;
	}
	void run( vector<int> &candidates, int target )
	{
		vector<vector<int>> res = combinationSum( candidates, target );
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
	int arr[] = {2, 3, 6, 7};
	vector<int> vv( arr, arr + 4 );
	Solution ss;
	ss.run( vv, 10 );
	return 0;
}