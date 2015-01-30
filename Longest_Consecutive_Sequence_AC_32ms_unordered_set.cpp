#include <iostream>

#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// https://oj.leetcode.com/problems/longest-consecutive-sequence/
class Solution
{
public:
	int longestConsecutive( vector<int> &num )
	{
		unordered_set<int> numSet( num.begin(), num.end() ), searched;
		//unordered_set is much faster than map
		int low, up;
		int longest = 0;
		for ( int i = 0; i < num.size(); ++i ) {
			if ( searched.find(num[i]) ==  searched.end()) {
				searched.insert(num[i]);
				low = num[i] - 1;
				up = num[i] + 1;
				while ( numSet.find( low ) != numSet.end() ) searched.insert(low--);
				while ( numSet.find( up ) != numSet.end() ) searched.insert(up++);
				if ( longest < up - low - 1 ) {		
					longest = up - low - 1;
				}
			}
		}
		return longest;
	}
};

int main()
{
	std::vector<int> v;
	v.push_back( 100 );
	v.push_back( 4 );
	v.push_back( 200 );
	v.push_back( 1 );
	v.push_back( 3 );
	v.push_back( 2 );

	Solution ss;
	cout << ss.longestConsecutive( v ) << endl;
	cout << "hello world" << endl;
}


