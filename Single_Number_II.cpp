#include <iostream>

using namespace std;

// https://oj.leetcode.com/problems/single-number-ii/

class Solution
{
public:
	int singleNumber( int A[], int n )
	{	
		int once =0;
		int twice = 0;
		int triple = 0;
		for(int i=0; i< n; ++i){
			triple = twice & A[i];
			twice = once & A[i] | twice;
			once = once | A[i];

			twice = twice & ~triple;
			once = once & ~ twice;
			once = once & ~ triple;
			triple = 0;
		}
		return once;
	}
	int twoNumber( int A[], int n ){
		int oneNum = 0;
		int twoNum = 0;
		int threeNum = 0;
		int fourNum = 0;
		for ( int i = 0 ; i < n ; i++ ) {
			fourNum = threeNum & A[i] ;
			threeNum = twoNum & A[i] | threeNum;
			twoNum = oneNum & A[i] | twoNum;
			oneNum = oneNum | A[i];

			oneNum = oneNum & ( ~threeNum );
			oneNum = oneNum & ( ~twoNum );
			oneNum = oneNum & ( ~fourNum );
			
			twoNum = twoNum & ( ~threeNum );
			twoNum = twoNum & ( ~fourNum );
			
			threeNum = threeNum &( ~fourNum);
			// threeNum = 0;
			fourNum = 0;
		}
		return twoNum;
	}

};

int main()
{
	// int A[] = {1, 2, 1, 3, 1, 3, 3,4,5,5,4,4,5,1,3,4,5,2};
	int A[] = {1, 2, 1, 3, 1, 3, 3};
	int n = 7;
	Solution ss;
	cout << ss.singleNumber( A, n ) << endl;
}