#include <iostream>
#include <climits>
using namespace std;
// https://leetcode.com/problems/jump-game-ii/

class Solution
{
public:

	int jump( int A[], int n )
	{
		if ( n <= 1 ) return 0;
		int step = 1;
		for ( int max = A[0], tmp_max = 0, pre_max = 0; max < n - 1; ) {
			tmp_max = 0;
			for ( int j = pre_max + 1; j <= max; ++j ) {
				if ( tmp_max < j + A[j] ) 
					tmp_max = j + A[j];
			}
			pre_max = max;
			max = tmp_max;
			step ++;
		}
		return step;
	}
	void run( int A[], int n )
	{
		cout << jump2( A, n ) << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	int A[] = {2, 3, 1,2, 1, 4};
	Solution ss;
	ss.run( A, 6 );
	return 0;
}