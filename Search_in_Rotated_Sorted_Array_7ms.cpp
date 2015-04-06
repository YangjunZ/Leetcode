#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int search( int A[], int n, int target )
	{
		int l = 0, r = n - 1, m;
		while ( l < r ) {
			m = ( l + r ) / 2;
			if ( target == A[m] ) return m;
			if ( A[m] <= A[r] && A[r] < A[l] ) { //l..max min.. m.. r
				if ( A[m] < target && target <= A[r] ) {
					l = m + 1;
					// cout << "hello"<<endl;
				} else {
					r = m - 1;
				}
			} else if ( A[r] < A[l] && A[l] <= A[m] ) { // l..m..max min ..r
				if ( A[l] <= target && target < A[m] ) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			} else { //l..m..r
				if ( target < A[m] )
					r = m - 1;
				else
					l = m + 1;
			}
		}
		if ( r == l && target == A[l] ) return l;
		return -1;
	}

	void run( int A[], int n, int target )
	{
		cout << search( A, n, target ) << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	// int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
	// int arr[] = {5, 1, 3};
	int arr[] = {1,3};
	Solution ss;
	// ss.run( arr, 8, 9 );
	ss.run( arr, 2, 3);

	return 0;
}