#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/candy/


//find pit, give candy to back edge, fix the candy of peak.
//same ratings between neighbor can get different candy
class Solution
{
public:
	
	int candy( vector<int> &ratings )
	{
		if ( ratings.size() <= 1 )
			return ratings.size();
		int pitIdx = 0, pitLen = 0;
		std::vector<int> candyV( ratings.size(), 1 );

		for ( int i = 1; i < ratings.size(); ++i ) {
			if (  ratings[i - 1] > ratings[i] ) {
				pitIdx = i;
				pitLen ++;
			}  else {
				if ( pitIdx != -1 ) {
					candyV[pitIdx] = 1;
					while ( pitIdx > 0 && ratings[pitIdx - 1] > ratings[pitIdx] && candyV[pitIdx - 1] <= candyV[pitIdx] ) {
						candyV[pitIdx - 1] = candyV[pitIdx] + 1;
						pitIdx --;
					}
				}
				if ( ratings[i - 1] == ratings[i] )
					candyV[i] = 1;
				else
					candyV[i] = candyV[i - 1] + 1;
				pitIdx = -1;
			}
		}
		if ( pitIdx != -1 ) {
			candyV[pitIdx] = 1;
			while ( pitIdx > 0 && ratings[pitIdx - 1] > ratings[pitIdx] && candyV[pitIdx - 1] <= candyV[pitIdx] ) {
				candyV[pitIdx - 1] = candyV[pitIdx] + 1;
				pitIdx --;
			}
		}
		// cout << "over" << endl;
		// print ( candyV );
		int sum = 0;
		for ( int i = 0; i < candyV.size(); ++i ) {
			sum = sum + candyV[i];
		}
		return sum;
	}

	void test( void )
	{
		std::vector<int> v;
		v.push_back( 3 );
		v.push_back( 3 );
		v.push_back( 2 );
		v.push_back( 3 );
		v.push_back( 3 );
		v.push_back( 2 );
		v.push_back( 2 );
		v.push_back( 2 );
		v.push_back( 1 );
		v.push_back( 2 );
		v.push_back( 2 );


		// v.push_back( 1 );
		// v.push_back( 2 );
		// v.push_back( 3 );
		// v.push_back( 4 );
		// v.push_back( 2 );
		// v.push_back( 2 );
		// v.push_back( 2 );
		// v.push_back( 1 );

		// v.push_back( 1 );
		// v.push_back( 2 );
		// v.push_back( 2 );
		print( v );
		cout << "sum:" << candy( v ) << endl;
	}
	void print( std::vector<int> v )
	{
		for ( int i = 0; i < v.size(); ++i )
			cout << v[i] << " ";
		cout << endl;
	}
};

int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}