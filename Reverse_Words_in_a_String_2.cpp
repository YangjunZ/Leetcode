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
		char * cptr = new char[str.size()+1];
		int cidx = 0;
		while (i >= 0 ) {
			// cout << i << endl;
			while (i >= 0 && str[i] == ' ') i--;
			while (i >= 0 && str[i] != ' ') i--;
			if (i + 1 >= 0 && str[i + 1] != ' ') {
				if( cidx > 0){
					// newstr = newstr + ' ';
					cptr[cidx++] = ' ';
				}
				cnt = i + 1;
				while (cnt < str.size() && str[cnt] != ' ') {
					// newstr = newstr + str[cnt];
					cptr[cidx++] = str[cnt];
					cnt++;
				}
				
				// cout << newstr << endl;
			}

		}
		cptr[cidx]='\0';
		string tmpstr(cptr);
		s=tmpstr;
		// s = newstr;
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
	s="pz! .xwy.,cga. vua frjrmcjf, xxw'izz vgthvpfhl sldudifok wvls orujxroi w. oo c?ymxlptr ff'?rh bsjjoyjwvx tj pqv.zlq ,jlu',j dg izq.fo wtvwqn teual jnsv.a .oclyrvg tkgag'a' !wsz?sclc pvhl.ypq vyin cn?z,kxg , u l?l glr zf'hew l'wmi .nlvgr u zfwzra? ot!emgg. rg,'.d.kp fn vat ba.myfqxe znzdrhh xjeubr taztndst v nep?bs .,pwin. e pi";
	ss.test(s);
	cout << "hello world" << endl;
	return 0;
}