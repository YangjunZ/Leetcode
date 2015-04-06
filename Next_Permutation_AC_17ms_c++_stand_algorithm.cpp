#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void nextPermutation( vector<int> &num )
	{
		//from back to front, find a reversed order pair
		//if not, sort the arr,
		//bug free, when sorted the arr , how to do if the first num is 0?
		//比原序列更大的最小字典序
		if ( num.size() <= 1 )
			return ;
		int i = num.size() - 1;
		while ( i > 0 ) {
			if ( num[i - 1] < num[i] ) break;
			--i;
		}
		// cout << i<<endl;
		reverse( num.begin() + i, num.end() );
		if ( i == 0 ) return;
		auto itr = upper_bound( num.begin() + i, num.end(), num[i - 1] );
		swap( num[i - 1], *itr );
	}

	void run( vector<int> &num )
	{
		nextPermutation( num );
		for ( int i = 0; i < num.size(); ++i ) {
			cout << num[i] << " ";
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	// int num0[] = {1, 2, 3};
	// int num0[] = {3, 2, 1};
	// int num0[] = {1, 3, 2};
	int num0[] = {1, 1, 1};

	vector<int> num( num0, num0 + 3 );
	Solution ss;
	ss.run( num );
	return 0;
}