#include <iostream>
#include <vector>
#include <cstdarg> //va_list
#include <algorithm>//sort

using namespace std;

//https://oj.leetcode.com/problems/maximum-gap/
//quick sort, then calculate max gap one by one


class Solution
{
public:

	int maximumGap(vector<int> &num)
	{
		if ( num.size() < 2) {
			return 0;
		}
		sort( num.begin(), num.end());
		std::vector<int>::iterator itr = num.begin();
		int pre = *itr;
		int delta = 0;
		itr ++;

		while ( itr != num.end()){
			if( *itr - pre > delta){
				delta = *itr - pre;
			}
			pre = *itr;
			itr ++;
		}
		return delta;
	}

	void test(int length, ...)
	{
		va_list pvar;
		std::vector<int> vint;
		va_start( pvar, length);
		for (int i = 0; i < length; i++) {
			vint.push_back( va_arg( pvar, int));
		}
		va_end(pvar);

		cout << maximumGap( vint) << endl;
	}
};

int main()
{
	Solution ss;
	ss.test(2, 2, 1);
	ss.test(3, 5, 2, 3);
	ss.test(4, 3, 6, 9, 1);
	return 0;
}