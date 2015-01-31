#include <iostream>

#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

// https://oj.leetcode.com/problems/longest-consecutive-sequence/
//negative, equal
class Solution
{
public:
	void radixSort_core( vector<int> &num, long long max ) //all the number >= 0
	{
		if ( num.size() <= 1 )
			return ;
		vector< vector<int> > buckets( 10, vector<int> () );//[-9, 9]
		int baseMax = 0;
		int index = 0;
		while ( max > 0 ) {
			max = max / 10;
			baseMax ++;
		}
		int base = 1;
		for ( int i = 1; i <= baseMax; ++i ) {
			for ( int j = 0; j < num.size(); ++j ) {
				index = ( ( num[j] ) / base ) % 10;
				buckets[index].push_back( num[j] );
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

	void radixSort( vector<int> &num )
	{
		// bucket_idx = (num[i]/base)%10
		int min_n = 0;
		int max_p = 0;
		vector<int> negative;
		vector<int> positive;
		for ( int i = 0; i < num.size(); ++i ) {
			if ( num[i] >= 0 ) {
				positive.push_back( num[i] );
				if ( max_p < num[i]  )
					max_p = num[i];
			} else {
				negative.push_back( 0 - num[i] );
				if ( num[i] < min_n )
					min_n = num[i];
			}
		}

		num.clear();
		// print( negative );
		if ( negative.size() > 0 ) {
			radixSort_core( negative, 0 - min_n );
			for ( int i = negative.size() - 1; i >= 0; --i ) {
				num.push_back( 0 - negative[i] );
			}
		}
		// print( num );
		if ( positive.size() > 0 ) {
			radixSort_core( positive, max_p );
			for ( int i = 0; i < positive.size(); ++i ) {
				num.push_back( positive[i] );
			}
		}
		// print( num );
	}


	int longestConsecutive( vector<int> &num )
	{
		if ( num.size() <= 1 ) {
			return num.size();
		}
		int longest = 0;
		int tmp, tmpCnt;

		radixSort( num );
		print( num );
		tmp = num[0];
		tmpCnt = 1;
		for ( int i = 1; i < num.size(); ++i ) {
			if ( num[i] == tmp ) {
				continue;
			} else if ( num[i] == tmp + 1 ) {
				tmp++;
				tmpCnt++;
			} else {
				if ( longest < tmpCnt )
					longest = tmpCnt;
				tmp = num[i];
				tmpCnt = 1;
			}
		}
		if ( longest < tmpCnt )
			longest = tmpCnt;
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
	// v.push_back( 100 );
	// v.push_back( 4 );
	// v.push_back( 200 );
	// v.push_back( 1 );
	// v.push_back( -169 );
	// v.push_back( 3 );
	// v.push_back( 2 );
	// v.push_back( -2 );
	// v.push_back( 2123434 );
	// v.push_back( -20000000 );
	// v.push_back( -9 );
	// v.push_back( -16 );
	v.push_back( 0 );
	v.push_back( -1 );
	v.push_back( 2 );
	v.push_back( 1 );
	v.push_back( 3 );
	v.push_back( 1 );

	Solution ss;
	cout << ss.longestConsecutive( v ) << endl;
	cout << "hello world" << endl;
}


