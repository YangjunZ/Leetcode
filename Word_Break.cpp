#include <iostream>
#include <unordered_set>
// #include <vector>

using namespace std;
// https://oj.leetcode.com/problems/word-break/




class Solution
{
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		//dp
		if ( dict.find(s)!= dict.end()) {
			return true;
		}
		bool **mtx = new bool*[s.size()];
		for (int i = 0; i < s.size(); i++) {
			mtx[i] = new bool[s.size()];
			for (int j = 0; j < s.size(); ++j) {
				mtx[i][j] = false;
			}
		}
		string tmpkey = "";
		for (int k = 1; k <= s.size(); k++) {
			for (int i = 0; i + k <= s.size(); ++i) {
				tmpkey = s.substr(i, k);
				if ( dict.find(tmpkey) != dict.end()) {
					// cout <<"find "<< tmpkey<<endl;
					mtx[i][i + k - 1] = true;
				} else {
					for (int m = 1; m < k; ++m) {
						if ( mtx[i][i + m - 1] && mtx[i + m][i + k-1]) {
							mtx[i][i + k-1] = true;
							// cout <<"assemble "<< tmpkey<<endl;
							break;
						}
					}
				}
			}
		}
		return mtx[0][s.size() - 1];
	}
	void test(void)
	{
		unordered_set<string> dict = {"leet", "code"};
		// unordered_set<string> dict = {"a", "b"};
		// string s = "ab";
		string s = "leetcode";
		if (wordBreak(s, dict)) {
			cout << "True" << endl;
		} else {
			cout << "false" << endl;
		}
	}
};

int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}