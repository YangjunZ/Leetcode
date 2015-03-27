#include <iostream>

using namespace std;


class Solution
{
public:
	int removeDuplicates( int A[], int n )
	{
		if ( n == 0 || n == 1 ) return n;
		int i = 1, len = 1, key = A[0];
		while ( i < n ) {
			while ( i < n && A[i] == key ) i++;
			if ( i < n ) {
				A[len] = A[i];
				key = A[i];
				len ++;
				i++;
			}
		}
		return len;
	}
	void print( int A[], int n )
	{
		n = removeDuplicates( A, n );
		int i = 0;
		while ( i < n ) {
			cout << A[i] << ",";
			i++;
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	// int A[] = {1,2,3,4,5,5,5,6,7,7,7,8,9};
	int A[] = {1,1};
	Solution ss;
	ss.print(A, 2);
	return 0;
}