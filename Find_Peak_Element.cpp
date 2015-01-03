#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/find-peak-element/
//find cur-pre,++-,the last +

class Solution
{
public:
	int findPeakElement(const vector<int> &num)
	{
		
		for (int i = 1; i < num.size(); i++) {
			if( num[i-1] > num [i] ){
				return i-1;
			}
		}

		return num.size()-1;
    }

	void test(int *arr, int size)
	{
		// cout << "size:"<<size<<" **"<<sizeof(arr)<<endl;
		std::vector<int> v;
		for (int i = 0; i < size; i++) {
			v.push_back(arr[i]);
		}
		cout << findPeakElement(v) << endl;
	}

};

int main()
{
	// cout << "hello world" << endl;
	Solution ss;
	int a[] = {1, 2, 3, 1, 6};
	ss.test(a, sizeof(a) / sizeof(int));
	return 0;
}