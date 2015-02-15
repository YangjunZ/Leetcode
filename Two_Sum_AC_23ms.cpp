#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://oj.leetcode.com/problems/two-sum/

class Solution
{
public:
	vector<int> twoSum( vector<int> &numbers, int target )
	{
		unordered_map<int, int> hashMap;
		vector<int> res;
		for ( int i = 0; i < numbers.size(); ++i ) {
			if ( hashMap.find( target - numbers[i] ) != hashMap.end() ) {
				cout << hashMap[target - numbers[i]] + 1 << "," << i + 1 << endl;
				res.push_back( hashMap[target - numbers[i]] + 1 );
				res.push_back( i + 1 );
				return res;
			} else {
				hashMap[numbers[i]] = i;
			}

		}
	}
};

void print( vector<int> &numbers, vector<int> &index )
{
	for ( int i = 0; i < index.size(); ++i ) {
		cout << numbers[ index[i] - 1] << ",";
	}
	cout << endl;
}


int main( int argc, char const *argv[] )
{
	/* code */
	vector<int> numbers = {-2, 7, 11, 5};
	Solution ss;
	ss.twoSum( numbers, 5 );
	return 0;
}