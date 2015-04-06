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
			if ( num[i - 1] < num[i] ) {
				int min_idx = i;
				int k = i + 1;
				while ( k < num.size() ) {
					if ( num[i - 1] < num[k] && num[k] <= num[min_idx] ) {
						min_idx = k;
					}
					k++;
				}
				int tmp = num[min_idx];
				num[min_idx] = num[i - 1];
				num[i - 1] =  tmp;
				//num[i..n-1] is descending
				k = num.size() - 1;
				while ( i < k ) {
					tmp = num[k];
					num[k] = num[i];
					num[i] = tmp;
					++i;
					--k;
				}
				// sort( num.begin() + i, num.end() );
				return ;
			}
			--i;
		}
		// sort( num.begin(), num.end() );
		i = 0;
		int k = num.size() - 1;
		while ( i < k ) {
			int tmp = num[k];
			num[k] = num[i];
			num[i] = tmp;
			++i;
			--k;
		}
		return ;
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
	int num0[] = {1, 3, 2};
	vector<int> num( num0, num0 + 3 );
	Solution ss;
	ss.run( num );
	return 0;
}