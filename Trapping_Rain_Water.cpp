#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int trap( int A[], int n )
	{
		if ( n <= 2 ) return 0;

		int low = 0, up = n - 1;
		int preMax = 0;
		int sum = 0;
		while ( low < up ) {
			if ( A[low] < A[up] ) {
				if ( A[low] > preMax ) {
					preMax = A[low];
				} else {
					sum += preMax - A[low];
				}
				low ++;
			} else {
				if ( A[up] > preMax ) {
					preMax = A[up];
				} else {
					sum += preMax - A[up];
				}
				up--;
			}
		}
		return sum;
	}
};


int main( int argc, char const *argv[] )
{
	/* code */
	int A[] = {0,1,1,1,0,2,1,0,1,3,2,1,2,1};//13
	Solution ss;
	cout << ss.trap(A,13)<<endl;
	return 0;
}