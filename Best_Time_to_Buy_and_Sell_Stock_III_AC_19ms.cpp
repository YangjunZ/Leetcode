#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/


class Solution
{
public:
	int maxProfit( vector<int> &prices )
	{
		if ( prices.size() <= 1 )
			return 0;
		int left_min;
		int right_min_valid;
		int right_min;
		int left_profit = 0;//max profit for [0,i]
		int right_profit = 0;//max profit for (i, size)
		int max_profit = 0;
		left_min = prices[0];
		right_min_valid = prices[1];

		for ( int i = 1; i < prices.size(); ++i ) {
			if ( left_profit < prices[i] - left_min ) {
				left_profit = prices[i] - left_min;
			}
			if ( prices[i] < left_min ) left_min = prices[i];

			if ( prices[i] == right_min_valid ) {//find the right max profit again
				right_profit = 0;
				if ( i + 1 < prices.size() ) {
					right_min_valid =  0x7fffffff;
					right_min = prices[i + 1];
					for ( int j = i + 2; j < prices.size(); ++j ) {
						if ( right_profit < prices[j] - right_min ){
							right_profit = prices[j] - right_min;
							right_min_valid = right_min;
						}
						if ( prices[j] < right_min )
							right_min = prices[j];
					}
				}

			}
			if ( max_profit < left_profit + right_profit )
				max_profit = left_profit + right_profit;
		}
		return max_profit;
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(6);
	v.push_back(2);
	v.push_back(3);
	// v.push_back(1);
	// v.push_back(4);
	// v.push_back(2);
	// v.push_back(5);
	// v.push_back(4);
	// v.push_back(2);

	cout << ss.maxProfit( v)<<endl;
	cout << "hello world" << endl;
	return 0;
}