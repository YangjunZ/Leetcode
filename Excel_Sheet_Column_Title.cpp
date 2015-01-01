#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
    	string str = "";
    	int reminder = 0;
    	// int quotient = 0;
    	int num = n;
    	while( num > 0){
    		reminder = num % 26;
    		if( reminder == 0)
    			reminder = 26;
    		// else
    		str += 'A' + (reminder -1);
    		num = (num-reminder) / 26;
    	}
    	// for( int i = str.length() -1; i >=0;i--){
    	// 	cout<<str[i];
    	// }
    	// cout  <<endl;
    	string rs = string(str.rbegin(),str.rend());
    	// cout <<rs<<endl<<endl;
        return rs;
    }
};

int main()
{
	cout << "hello world"<<endl;
	Solution ss =  Solution();
	int num = 1;

	while (num > 0){
		cout<<"input num: ";
		cin >> num;
		ss.convertToTitle(num);
	}
	// ss.convertToTitle(1);
	return 0;
}