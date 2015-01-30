#include <iostream>

#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// https://oj.leetcode.com/problems/longest-consecutive-sequence/
class Solution
{
public:
	void radixSort( vector<int> &num )
	{
		// bucket_idx = (num[i]/base)%10
		vector< vector<int> > buckets( 19, vector<int> () );//[-9, 9]
		int baseMax = 3;
		int base = 1;
		int index = 0;
		int max = 0x80000000;
		for ( int i = 0; i < num.size(); ++i ) {
			if ( max < num[i] || max < 0 - num[i] )
				max = num[i];
		}
		if ( max < 0 )
			max = 0 - max;
		baseMax = 0;
		while ( max > 0 ) {
			max = max / 10;
			baseMax ++;
		}
		cout << "baseMax:" << baseMax << endl;
		for ( int i = 1; i <= baseMax; ++i ) {
			for ( int j = 0; j < num.size(); ++j ) {
				if ( num[j] >= 0 ) {
					index = ( ( num[j] ) / base ) % 10;
					buckets[index + 10 ].push_back( num[j] );
				} else {
					index = ( ( 0 - num[j] ) / base ) % 10;
					buckets[9-index].push_back( num[j] );
				}
			}
			num.clear();
			for ( int j = 0; j < buckets.size(); ++j ) {
				for ( int k = 0; k < buckets[j].size(); ++k ) {
					num.push_back( buckets[j][k] );
				}
				buckets[j].clear();
			}

			base = base * 10;
		}
	}


	int longestConsecutive( vector<int> &num )
	{
		if ( num.size() == 0 ) {
			return 0;
		}
		int longest = 0;
		int tmp, tmpCnt;

		radixSort( num );
		print(num);
		tmp = num[0];
		tmpCnt = 1;
		for ( int i = 1; i < num.size(); ++i ) {
			if ( num[i] == tmp + 1 ) {
				tmp++;
				tmpCnt++;
			} else {
				if ( longest < tmpCnt )
					longest = tmpCnt;
				tmp = num[i];
				tmpCnt = 1;
			}
		}
		return longest;
	}
	void print( vector<int> num )
	{
		for ( int i = 0; i < num.size(); ++i ) {
			cout << num[i] << ",";
		}
		cout << endl;
	}
};

int main()
{
	std::vector<int> v;
	v.push_back( 100 );
	v.push_back( 4 );
	v.push_back( 200 );
	v.push_back( 1 );
	v.push_back( -169 );
	v.push_back( 3 );
	v.push_back( 2 );
	v.push_back( -2 );
	v.push_back( 2123434 );
	v.push_back( -20000000 );
	v.push_back( -9 );
	v.push_back( -16 );

	Solution ss;
	cout << ss.longestConsecutive( v ) << endl;
	cout << "hello world" << endl;
}


