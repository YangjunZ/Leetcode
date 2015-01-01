#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://oj.leetcode.com/problems/compare-version-numbers/
//the number of dot '.'
//split version str by ., compare the number frome left to right.
//get the same level, convert to num,

class Solution
{
public:

	string getLevel(string version, int *idx)
	{
		int start = *idx;
		int end = start;

		while ( version[ start] == '.'&& start < version.size() ) start++;
		end = start;
		while ( version[end] != '.' && end < version.size()) end ++;
		string levelstr = version.substr( start, end - start);

		*idx = end;
		return levelstr;
	}

	int cmp(string str1, string str2)
	{
		int i1 = 0;
		while (str1[i1] == '0' && i1 < str1.size()) i1 ++;
		int i2 = 0;
		while (str2[i2] == '0' && i2 < str2.size()) i2 ++;

		if(str1.size() - i1 > str2.size() - i2) return 1;
		if(str1.size() - i1 < str2.size() - i2) return -1;
		while( i1 < str1.size() && i2 < str2.size()){
			if( str1[i1] > str2[i2]) return 1;
			if( str1[i1] < str2[i2]) return -1;
			i1 ++;
			i2 ++;
		}
		if( i1 < str1.size()) return 1;
		if( i2 < str2.size()) return -1;
		return 0;
	}

	int compareVersion(string version1, string version2)
	{
		int i1 = 0;
		int i2 = 0;
		// while (i1 < version1.size()) {
		// 	cout << getLevel(version1, &i1) << " ";
		// }

		// while (i2 < version2.size()) {
		// 	cout << getLevel(version2, &i2) << " ";
		// }

		int res = 0;
		while( i1 < version1.size() && i2 < version2.size()){
			res = cmp( getLevel(version1, &i1), getLevel(version2, &i2));
			if( res != 0) return res;
		}
		

		// for compare( 1.0.0, 1)
		while ( i1 < version1.size()){
			res = cmp(getLevel(version1, &i1), "0");
			if( res != 0) return 1;
		}
		while ( i2 < version2.size()){
			res = cmp(getLevel(version2, &i2), "0");
			if( res != 0) return -1;
		}

		return 0;
	}

	void test(string str1, string str2){
		cout << compareVersion( str1, str2)<<endl;
	}
};

int main()
{
	string version1, version2;
	// cin >> version1 >> version2;
	Solution ss;
	ss.test( "12.243", "0.23.34");
	ss.test( "1.1", "1.23.34");
	ss.test( "1.23.34", "1.23.34");
	ss.test( "0.0.1", "0.0.0.2");
	ss.test( "1", "0");
	ss.test( "1", "1.1");
	ss.test( "1.0", "1");

	return 0;
}