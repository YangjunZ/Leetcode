#include <iostream>
#include <string>
#include <vector>
using namespace std;
// https://oj.leetcode.com/problems/reverse-words-in-a-string/


class Solution
{
public:
	void reverseWords(string &s)
	{

		//traverse the string, split string by space, push the index of words to a vector, than genarate a new string

		string str = s;
		// cout << str << endl;
		int i = str.size() - 1;
		int cnt;
		string newstr = "";

		while (i >= 0 ) {
			// cout << i << endl;
			while (i >= 0 && str[i] == ' ') i--;
			while (i >= 0 && str[i] != ' ') i--;
			if (i + 1 >= 0 && str[i + 1] != ' ') {
				if( newstr.size() > 0)
					newstr = newstr + ' ';
				cnt = i + 1;
				while (cnt < str.size() && str[cnt] != ' ') {
					newstr = newstr + str[cnt];
					cnt++;
				}
				
				// cout << newstr << endl;
			}

		}
		s = newstr;
		// cout << newstr << endl;
	}

	void test( string &s){
		reverseWords(s);
		cout << '#' << s << '#' << endl;
	}
};


int main()
{
	Solution ss;
	string s = "this is a joke";
	ss.test(s);
	s=" ";
	ss.test(s);
	s=" 1";
	ss.test(s);
	cout << "hello world" << endl;
	return 0;
}