#include <iostream>

#include <vector>

using namespace std;

class Solution
{
public:
	int maxProfit( vector<int> &prices )
	{
		int buy1 = 0x80000000, buy2 = 0x80000000;
		int sell1 = 0, sell2 = 0;
		int tmp;
		for ( int i = 0; i < prices.size(); ++i ) {
			tmp = prices[i];
			sell2 = (sell2 > buy2 + tmp )? sell2 : buy2 + tmp;
			buy2 = (buy2 > sell1 - tmp) ? buy2 : sell1 - tmp;
			sell1 = (sell1 > buy1 + tmp) ? sell1 : buy1 + tmp;
			buy1 = (buy1 > 0 - tmp) ? buy1 : 0 - tmp;
			// cout << buy1 << " "<< sell1 << " "<< buy2<<" "<<sell2<<endl;
		}
		return sell2;
	}
};

int main( int argc, char const *argv[] )
{
	Solution ss;
	std::vector<int> v;
	// v.push_back(1);
	v.push_back(6);
	v.push_back(2);
	// v.push_back(3);
	// v.push_back(1);
	// v.push_back(4);
	// v.push_back(2);
	// v.push_back(5);
	// v.push_back(4);
	// v.push_back(2);

	cout << ss.maxProfit( v)<<endl;
	return 0;
}