#include <iostream>
#include <vector>

using namespace std;
// https://leetcode.com/problems/container-with-most-water/

//bug free: one height,

class Solution
{
public:
	int getMin( int y1, int y2 )
	{
		return y1 < y2 ? y1 : y2;
	}

	int maxArea( vector<int> &height )
	{
		int low = 0, up = height.size() - 1;
		int maxCapacity = 0;
		int tmpCapacity = 0;
		int tmp;
		while ( low < up ) {
			tmpCapacity = ( up - low ) * getMin( height[low], height[up] );
			if ( maxCapacity < tmpCapacity )
				maxCapacity = tmpCapacity;
			if ( height[low] < height[up] ) {
				tmp = height[low++];
				while ( height[low] <= tmp ) low++;
			} else {
				tmp = height[up--];
				while ( height[up] <= tmp ) up--;
			}
		}
		return maxCapacity;
	}
};


// 1,2,3,4,5
//2,1,4,5,8,2,1
//1,1,1,1,1
//1,2,3,2,1
int main( int argc, char const *argv[] )
{
	/* code */
	vector<int> v={1,2,3,4,5};
	Solution ss;
	cout << ss.maxArea(v)<<endl;
	return 0;
}