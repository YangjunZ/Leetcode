#include <iostream>
#include <vector>

using namespace std;

// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// buy stock at bottom, and sell stock at peak

class Solution
{
public:
	int maxProfit( vector<int> &prices )
	{
		if ( prices.size() < 2 )
			return 0;
		int bottom;		
		int res = 0;
		int cur_profit= 0;

		bottom = prices[0];
		for ( int i = 1; i < prices.size(); ++i ) {
			if( cur_profit <= prices[i] - bottom)
				cur_profit = prices[i] - bottom;
			else {
				res += cur_profit;
				cur_profit = 0;
				bottom = prices[i];
			}
		}
		if(cur_profit != 0){
			res += cur_profit;
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	Solution ss;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	v.push_back(5);

	cout << ss.maxProfit( v)<<endl;
	return 0;
}