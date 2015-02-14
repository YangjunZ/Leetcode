#include <iostream>

using namespace std;


// https://oj.leetcode.com/problems/merge-sorted-array/
//bug free: assume ascending order
//
class Solution
{
public:
	void merge( int A[], int m, int B[], int n )
	{
		int idx = m + n - 1;
		int aIdx = m - 1;
		int bIdx = n - 1;

		//m <=0, n<=0
		while ( aIdx >= 0 && bIdx >= 0 ) {
			if ( A[aIdx] < B[bIdx] ) {
				A[idx] = B[bIdx];
				bIdx --;
			} else {
				A[idx] = A[aIdx];
				aIdx --;
			}
			idx--;
		}
		while ( aIdx >= 0 ) {
			A[idx--] = A[aIdx--];
		}
		while ( bIdx >= 0 ) {
			A[idx--] = B[bIdx--];
		}
	}
};

void print( int a[], int size )
{
	for ( int i = 0; i < size; ++i ) {
		cout << a[i] << ",";
	}
	cout << endl;
}

int main( int argc, char const *argv[] )
{

	return 0;
}