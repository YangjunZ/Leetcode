#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.com/problems/combination-sum-ii/

//bug free
//all number only be used once
//solution must not be duplicate

class Solution
{
public:
	void findSolution( vector<int> &num, vector<vector<int>> &res, vector<int> &stk, int idx, int tmpTarget )
	{
		//for num[i..n-1], and tmp target, retuen solution
		//exit condition, idx over the bound, tmpTarget is impossible
		if ( num.size() <= idx )
			return;
		if ( tmpTarget < num[idx] )
			return;

		//add current number
		if ( num[idx] == tmpTarget ) {
			stk.push_back( num[idx] );
			res.push_back( stk );
			stk.pop_back();
			return;//avoid duplicate
		} else if ( num[idx] < tmpTarget ) {
			stk.push_back( num[idx] );
			findSolution( num, res, stk, idx + 1, tmpTarget - num[idx] );
			stk.pop_back();
		}

		//try next
		idx ++;
		while ( idx < num.size() && num[idx] == num[idx - 1] ) idx++; //avoid duplicate
		findSolution( num, res, stk, idx, tmpTarget );
	}

	vector<vector<int> > combinationSum2( vector<int> &num, int target )
	{
		vector<vector<int>> res;
		vector<int> stk;
		sort( num.begin(), num.end() );
		findSolution( num, res, stk, 0, target );
		return res;
	}

	void run( vector<int> &num, int target )
	{
		vector<vector<int>> res = combinationSum2( num, target );
		for ( int i = 0; i < res.size(); ++i ) {
			cout << "[";
			for ( int j = 0; j < res[i].size(); ++j ) {
				cout << res[i][j]<<",";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	int arr[] = {10, 1, 2, 7, 6, 1, 5}; //7
	vector<int> num( arr, arr + 7 );
	Solution ss;
	ss.run(num, 10);
	return 0;
}