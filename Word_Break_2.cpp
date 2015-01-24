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
		unordered_set<int> inLength;// item in inLength set, means [0, item] is assembled by dict
		inLength.insert(-1);
		string tmpkey = "";
		for (int i = 0; i < s.size(); i++) {
			for (auto itr = inLength.begin(); itr != inLength.end(); ++itr) {
				// cout << i<<" itr: "<<*itr<<endl;
				tmpkey = s.substr(*itr + 1, i - (*itr));
				if (dict.find(tmpkey) != dict.end()) {
					inLength.insert(i);
					break;
				}
			}
			// if ( inLength.find(i) == inLength.end() && dict.find( s.substr(0, i + 1)) != dict.end()) {
			// 	inLength.insert(i);
			// }  //instead by *itr = -1
		}
		return inLength.find(s.size() - 1) != inLength.end();
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