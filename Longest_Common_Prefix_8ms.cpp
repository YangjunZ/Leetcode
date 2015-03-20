#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix( vector<string> &strs )
	{
		if ( strs.size() == 0 )
			return "";
		if ( strs.size() == 1 )
			return strs[0];
		char ch;
		int cnt = 0;
		int strCnt = 0;
		while ( true ) {
			if ( strs[0].length() > cnt )
				ch = strs[0][cnt];
			else
				break;
			strCnt = 1;
			while ( strCnt < strs.size() ) {
				if ( cnt >= strs[strCnt].length() || ch != strs[strCnt][cnt] )
					break;
				strCnt ++;
			}
			if ( strCnt != strs.size() )
				break;
			cnt ++;
		}
		// cout << cnt << endl;
		return strs[0].substr( 0, cnt );
	}
	void print (vector<string> &strs )
	{
		cout<< longestCommonPrefix(strs)<<endl;
	}
};

int main(int argc, char const *argv[])
{
	Solution ss;
	vector<string> strs;
	strs.push_back("hello");
	strs.push_back("heni");
	strs.push_back("hexxxllo");
	strs.push_back("h");
	ss.print(strs);
	return 0;
}