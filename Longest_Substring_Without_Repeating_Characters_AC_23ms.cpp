#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/



class Solution
{
public:
	int lengthOfLongestSubstring( string s )
	{
		if ( s.size() <= 1 ) {
			return s.size();
		}
		vector<int> hashTable( 128, -1 );
		int start, cur;
		start = cur = 0;
		int max = 0;
		int len = s.size();
		while ( cur < len ) {
			if ( hashTable[s[cur]] == -1 ) {
				hashTable[ s[cur]] = cur;
			} else {
				if ( max < cur - start )
					max = cur - start;
				while ( start <= hashTable[s[cur]] ) {
					hashTable[ s[start]] = -1;
					start ++;
				}
				hashTable[s[cur]] = cur;
			}
			++cur;
		}
		if ( max < cur - start )
			max = cur - start;
		return max;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	cout << ss.lengthOfLongestSubstring("")<<endl;
	cout << ss.lengthOfLongestSubstring("abca")<<endl;
	
	cout << ss.lengthOfLongestSubstring("abcabcbb")<<endl;
	cout << ss.lengthOfLongestSubstring("aaabbdbb")<<endl;
	return 0;
}