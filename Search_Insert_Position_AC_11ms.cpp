#include <iostream>

using namespace std;

class Solution
{
public:
	int searchInsert( int A[], int n, int target )
	{
		if ( n == 0 )
			return 0;
		int l = 0, u = n - 1, m;
		while ( l < u ) {
			m = ( l + u ) / 2;
			if ( target == A[m] )
				return m;
			if ( target < A[m] ) {
				u = m - 1;
			} else {
				l = m + 1;
			}
		}
		if ( A[l] == target )
			return l;
		else if ( A[l] < target )
			return l + 1;
		return l;
	}

	void run(int A[], int n, int target){
		cout << searchInsert(A, n, target)<<endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	// int A[] = {1,3,5,6};
	int A[] = {1};
	Solution ss;
	// ss.run(A,4,2);
	// ss.run(A,4,0);
	// ss.run(A,4,7);

	ss.run(A,1,1);
	ss.run(A,1,2);
	ss.run(A,1,0);
	return 0;
}
