#include <iostream>

#include <vector>

using namespace std;
// https://leetcode.com/problems/search-for-a-range/

class Solution
{
public:
	vector<int> searchRange( int A[], int n, int target )
	{
		//bug free,

		vector<int> res;
		if ( n == 0 ) {
			res.push_back( -1 );
			res.push_back( -1 );
			return res;
		}

		int upper_bound = -1, lower_bound = -1;
		int step, cur, base = 0, cnt = n;
		while ( cnt ) {
			step = cnt >> 1;
			cur = base + step;
			if ( A[cur] < target ) {
				base = cur + 1;
				cnt -= step + 1;
			} else {
				cnt = step;
			}
		}
		if ( base < n && A[base] ==  target ) {
		// if (A[base] ==  target ) {
			lower_bound = base;
		} else if ( base + 1 < n && A[base] == target ) {
			lower_bound = base + 1;
		} else { //not found
			res.push_back( -1 );
			res.push_back( -1 );
			return res;
		}

		cnt = n;
		base = 0;
		while ( cnt ) {
			step = cnt >> 1;
			cur = step + base;
			if ( target < A[cur] ) {
				cnt = step;
			} else {
				base = cur + 1;
				cnt -= step + 1;//?
			}
		}
		if ( base < n && A[base] == target ) {
		// if (A[base] == target ) {
			upper_bound = base;
		} else if ( base - 1 >= 0 && A[base - 1] == target ) {
			upper_bound = base - 1;
		} else {
			cout << "error" << endl;
		}
		res.push_back( lower_bound );
		res.push_back( upper_bound );
		return res;
	}

	void run( int A[], int n, int target )
	{
		vector<int> res = searchRange( A, n, target );
		for ( int i = 0; i < res.size(); ++i ) {
			cout << res[i] << ",";
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	int A[] = {5, 5,7, 7, 8, 8, 9};//7
	// int A[] = {0, 0, 0, 0, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 7, 7, 8, 9, 9, 9, 10}; //

	Solution ss;
	ss.run(A, 6, 9);
	// ss.run( A, 20, 10 );
	return 0;
}