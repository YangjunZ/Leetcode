#include <iostream>
#include <vector>

using namespace std;

//bug free : same value
class Solution
{
public:

	double findKth( int A[], int m, int B[], int n, int k )
	{
		//find the unuseable part
		if ( m == 0 )
			return B[k - 1];
		if ( n == 0 )
			return A[k - 1];

		int a = m / 2;
		int b = n / 2;
		if ( A[a] < B[b] ) {
			if ( a + 1 + b  < k ) { //A[a] rank must less than a+ 1 + b + 1
				return findKth( &A[a + 1], m - a - 1, B, n, k - a - 1 );
			} else {//B[b] must rank large than a+1+b
				return findKth( A, m, B, b, k );
			}
		} else {
			if ( a + 1 + b  < k ) { //B[b] rank must less than a+ 1 + b + 1
				return findKth( A, m, &B[b + 1], n - b - 1, k - b - 1 );
			} else {//A[a] must rank large than a+1+b, k<=a+b+1
				return findKth( A, a, B, n, k );
			}
		}

	}

	double findMedianSortedArrays( int A[], int m, int B[], int n )
	{
		//odd, return Arr[k] ,(len = 2k+1), else return (Arr[k-1]+Arr[k])/2, (len=2k)
		int k = ( m + n ) / 2;
		int val1 = findKth( A, m, B, n, k );		
		if ( ( m + n ) % 2 == 0 ) {
			return double( findKth( A, m, B, n, k + 1 ) + val1 ) / 2;
		} else
			return val1;
	}
};


int main( int argc, char const *argv[] )
{
	/* code */
	int A[] = {1, 3, 5, 7};
	int B[] = {2, 4, 6, 8};
	Solution ss;
	cout << ss.findMedianSortedArrays( A, 4, B, 4 ) << endl;
	return 0;
}