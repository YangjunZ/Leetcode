#include <iostream>

using namespace std;
// First Missing Positive

class Solution
{
public:
	int firstMissingPositive( int A[], int n )
	{
		for ( int i = 0; i < n; ++i ) {
			while ( 0 < A[i] &&  A[i] <= n && A[A[i] - 1] != A[i] ) {
				swap( A[i], A[A[i] - 1] );
			}
		}
		for ( int i = 0; i < n; ++i ) {
			if ( A[i] != i + 1 )
				return i + 1;
		}
		return n + 1;
	}

	void run( int A[], int n )
	{
		cout << firstMissingPositive( A, n ) << endl;
		for ( int i = 0; i < n; i++ ) {
			cout << A[i] << ",";
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	// int A[] = {2, 3, 1, 1, - 3, 5, 6,4};
	int A[] = {2, 3, 1, 7, 8 , 5, 6, 4};
	Solution ss;
	ss.run( A, 8 );
	return 0;
}