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
		unordered_set<int> numSet( num.begin(), num.end() );
		map<int, bool> isVisit;
		for ( int i = 0; i < num.size(); i++ ) {
			isVisit[num[i]] = false;
		}
		
		int low, up;
		int longest = 0;
		for ( int i = 0; i < num.size(); ++i ) {
			if ( isVisit[num[i]] == false ) {
				isVisit[num[i]] = true;
				low = num[i] - 1;
				up = num[i] + 1;
				while ( numSet.find( low ) != numSet.end() ) isVisit[low--] = true;
				while ( numSet.find( up ) != numSet.end() ) isVisit[up++] = true;
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


