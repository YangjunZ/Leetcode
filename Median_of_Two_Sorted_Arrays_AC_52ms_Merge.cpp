#include <iostream>
#include <vector>

using namespace std;

//bug free : same value
class Solution
{
public:
	static int getNext( int A[], int &as, int m, int B[], int &bs, int n )
	{

		while ( as < m && bs < n  ) {
			if ( A[as] < B[bs] ) {
				as++;
				return A[as - 1];
			} else {
				bs++;
				return B[bs - 1];
			}
		}
		while ( as < m ) {
			as++;
			return A[as - 1];
		}
		while ( bs < n ) {
			bs ++;
			return B[bs - 1];
		}
	}

	double findMedianSortedArrays( int A[], int m, int B[], int n )
	{
		// if ( m + n == 0 )
		//  return 0;
		// if ( m + n == 1 ) {
		//  if ( m == 1 )
		//      return A[0];
		//  if ( n == 1 )
		//      return B[0];
		// }

		int median_Cnt_MAX = (m + n) / 2;
		// cout << median_Cnt_MAX<<endl;
		int as, bs, cnt;
		as = bs = cnt = 0;
		if ( ( m + n ) % 2 == 1 ) {
			while ( cnt < median_Cnt_MAX ) {
				getNext( A, as, m, B, bs, n );
				cnt++;
			}
			return getNext( A, as, m, B, bs, n );
		} else {
			while ( cnt < median_Cnt_MAX - 1 ) {
				getNext( A, as, m, B, bs, n );
				cnt++;
			}
			return double( getNext( A, as, m, B, bs, n ) + getNext( A, as, m, B, bs, n ) ) / 2;
		}
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