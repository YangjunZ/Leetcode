#include <iostream>
// #include
using namespace std;
// https://oj.leetcode.com/problems/maximum-product-subarray/
// num in array, negative, positive integer and zero


class Solution
{
public:
	int getFirstNegative(int A[], int start, int end)
	{
		while (start < end) {
			if (A[start] < 0)
				return start;
			start  ++;
		}

		return -1;
	}

	int getLastNegative(int A[], int start, int end)
	{
		end --;
		while (start <= end) {
			if (A[end] < 0)
				return end;
			end --;
		}
		return -1;
	}

	int getSegmentAndNegativeCnt(int A[], int *start, int end)
	{
		int negativeCnt = 0;
		int i = *start;
		while (i < end) {
			if ( A[i] < 0)
				negativeCnt++;
			if (A[i] == 0)
				break;
			i++;
		}
		*start = i;
		return negativeCnt;
	}
	int getMaxProduct(int A[], int start, int end, int max_product)
	{
		int cur_product = 1;
		int isValid = 0; //[-2, 0, -1]
		for (int i = start; i < end; i++) {
			isValid = 1;
			cur_product = cur_product * A[i];
		}
		if (isValid == 1 && cur_product > max_product)
			return cur_product;
		return max_product;
	}

	int maxProduct(int A[], int n)
	{

		int max_product, cur_product;
		max_product = 1 << 31;
		cur_product = 1;

		int idx = 0;
		int pre_idx = 0;
		int negativeCnt = 0;
		int lastNegative, firstNegative;
		while ( idx < n) {
			pre_idx = idx;
			negativeCnt = getSegmentAndNegativeCnt(A, &idx, n);

			if (idx < n && max_product < 0) { //find zero
				max_product = 0; //[0]
				// cout<<"find zero"<<endl;
			}
			if ( idx - pre_idx > 0) {
				if (negativeCnt == 1 && idx - pre_idx == 1 && A[pre_idx] > max_product) {  //this segment only have one negative num,[-1]
					max_product = A[pre_idx];
				} else if (negativeCnt % 2 == 0) {
					cur_product = 1;
					for (int i = pre_idx; i < idx; i++) {
						cur_product = cur_product * A[i];
					}
					if (cur_product > max_product)
						max_product = cur_product;
				} else {//[2,3,-1,3,4,-1,6,8],[-2,0,-1]
					lastNegative = getLastNegative(A, pre_idx, idx);
					max_product = getMaxProduct(A, pre_idx, lastNegative, max_product);


					firstNegative = getFirstNegative(A, pre_idx, idx);
					max_product = getMaxProduct(A, firstNegative + 1, idx, max_product);
				}
			}
			idx ++;
		}
		return max_product;
	}
};


int main()
{
	Solution ss;
	int arr[] = {3, -1, 4};
	cout << ss.maxProduct(arr, 3) << endl;
	int arr2[] = { -2};
	cout << ss.maxProduct(arr2, 1) << endl;
	int arr3[] = { 0};
	cout << ss.maxProduct(arr3, 1) << endl;
	int arr4[] = { -2, 0, -1};
	cout << ss.maxProduct(arr4, 3) << endl;
	return 0;
}