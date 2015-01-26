#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/gas-station/

//find the gas station, when the car arrive it, the capacity of gas tank is least.

class Solution
{
public:
	int canCompleteCircuit( vector<int> &gas, vector<int> &cost )
	{
		int min = 0x7fffffff;
		int idx = 0;
		int cur = 0;
		for ( int i = 0; i < gas.size(); ++i ) {
			cur = cur - cost[i] + gas[i];
			if ( cur < min ) {
				min = cur;
				idx = i + 1;
			}
		}
		
		if ( cur >= 0 ) {
			if ( idx == gas.size() ) idx = 0;
			return idx;
		}
		return -1;
	}
	void test( void )
	{
		std::vector<int> gas, cost;
		gas.push_back( 1 );
		gas.push_back( 2 );
		gas.push_back( 5 );
		gas.push_back( 4 );

		cost.push_back( 5 );
		cost.push_back( 3 );
		cost.push_back( 2 );
		cost.push_back( 2 );

		cout << canCompleteCircuit(gas, cost) <<endl;
	}
};

int main()
{
	Solution ss;
	ss.test();
	cout << " hello world" << endl;
	return 0;

}

