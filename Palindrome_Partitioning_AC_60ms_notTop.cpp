#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/palindrome-partitioning/


class Solution
{
public:
	void print( vector<vector<string> > vv )
	{
		for ( int i = 0; i < vv.size(); ++i ) {
			cout << "[ ";
			for ( int j = 0; j < vv[i].size(); ++j ) {
				// cout <<"\""<<vv[i][j]<<"\",";
				cout <<vv[i][j]<<",";
			}
			cout <<"]"<<endl;
		}
	}

	vector<string> findPalindrome( string s, int start )
	{
		std::vector<string> v;
		int low, up;
		for ( int i = start; i < s.size(); ++i ) {
			if ( s[i] == s[start] ) {
				low = start + 1; up = i - 1;
				while ( low < up ) {
					if ( s[low] != s[up] )
						break;
					low ++ ;
					up--;
				}
				if ( low >= up ) {
					v.push_back( s.substr( start, i - start + 1 ) );
				}
			}
		}
		return v;
	}

	vector<vector<string> > partition( string s )
	{
		std::vector<std::vector<string> > res;
		std::vector< int > lenV;
		std::vector<string> tmpV = findPalindrome( s, 0 );
		// std::vector<int> vv;
		for ( int i = 0; i < tmpV.size(); ++i ) {
			lenV.push_back( tmpV[i].size() );
			std::vector<string> tmp;
			tmp.push_back( tmpV[i] );
			res.push_back( tmp );
		}
		// lenV.push_back( tmpV );


		for ( int i = 1; i < s.size(); ++i ) {
			//find Palindrome, idx
			tmpV = findPalindrome( s, i );
			vector<vector<string> > tmpres;
			vector<int > tmplen;
			for ( int j = 0; j < tmpV.size(); ++j ) {
				for ( int k = 0; k < res.size(); ++k ) {
					if ( lenV[k] == i ) {
						tmpres.push_back(res[k]);
						tmpres.back().push_back(tmpV[j]);
						// res[k].push_back( tmpV[j] );
						tmplen.push_back( lenV[k] + tmpV[j].size());
					} else if ( lenV[k] > i ) {
						// continue;
						if(j==0){//just copy once
							tmpres.push_back(res[k]);
							tmplen.push_back( lenV[k]);
						}
					} else {
						// cout << "error" << i << " " << lenV[k] << endl;
					}
				}
			}
			res = tmpres;
			lenV = tmplen;
			// cout<<"Index:" << i<<","<<endl;
			// print(res);
			// cout <<endl;

		}
		return res;
	}

	
};

int main()
{
	// string s = "abaacddc";
	string s = "aab";
	Solution ss;
	ss.print(ss.partition(s));
	cout << "hello world" << endl;
	return 0;
}