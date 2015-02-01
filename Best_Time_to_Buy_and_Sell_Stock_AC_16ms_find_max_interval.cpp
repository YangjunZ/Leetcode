#include <iostream>
#include <vector>
using namespace std;
//Best Time to Buy and Sell Stock
// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/


//only on transaction, just buy once and sell once,
class Solution
{
public:
	int maxProfit( vector<int> &prices )
	{
		if ( prices.size() <= 1 )
			return 0;
		int min = prices[0];
		int res = 0;
		for ( int i = 1; i < prices.size(); ++i ) {
			res = res > prices[i] - min ? res : prices[i] - min;
			min = min < prices[i] ? min : prices[i];
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(10);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(6);
	Solution ss;
	cout << ss.maxProfit(v)<<endl;
	return 0;
}