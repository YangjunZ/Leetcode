#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib> //atoi strtol
using namespace std;
// https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
//a vector to store the num to operator,
//not cover the big num case

class Solution
{
public:
	int isOperator(string str)
	{
		if (str == "+") return 1;
		if (str == "-") return 1;
		if (str == "*") return 1;
		if (str == "/") return 1;
		return 0;
	}

	int strToNum(string str)
	{
		return atoi(str.c_str());
	}

	int calc(int num1, int num2, string str)
	{
		if (str == "+")
			return num1 + num2;
		if (str == "-")
			return num1 - num2;
		if (str == "*")
			return num1 * num2;
		if (str == "/")
			return num1 / num2;
	}

	int evalRPN(vector<string> &tokens)
	{
		std::stack<int> stk;
		int i = 0;
		int num1 = 0; int num2 = 0;
		int res = 0;
		while (i < tokens.size()) {
			if ( isOperator( tokens[i])) {
				num2 = stk.top();
				stk.pop();
				num1 = stk.top();
				stk.pop();
				res = calc(num1, num2, tokens[i]);
				stk.push( res);
			} else {
				stk.push( strToNum( tokens[i]));
			}
			i ++;
		}
		// if (stk.size() != 1)
		// 	cout << "error" << endl;
		return stk.top();
	}

	
};

int main()
{
	cout << "hello world"<<endl;
	return 0;
}