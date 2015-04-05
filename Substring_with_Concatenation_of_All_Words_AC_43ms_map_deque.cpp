#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;


// Substring with Concatenation of All Words
//bug free, whether the words in L is duplicate,assume not


class Solution
{
public:
	void clearfindCnt( vector<int> &findCnt, deque<int> &dq  )
	{
		while ( dq.size() ) {
			findCnt[dq.back()] ++;
			dq.pop_back();
		}
	}
	void shiftfindCntUntil(vector<int> &findCnt, deque<int> &dq, int token )
	{
		// cout << "token:"<<token<<endl;
		while (  dq.front() != token ) {
			findCnt[ dq.front()] ++;
			dq.pop_front();
		}
		// if ( dq.size() == 0 )
		// 	cout << "error" << endl;
		findCnt[token]++;
		dq.pop_front();
	}

	vector<int> findSubstring( string S, vector<string> &L )
	{
		//map to check wether string, arr to check whether ok
		vector<int> res;
		int ws = L[0].length();
		int ss = S.size();
		int ls = L.size();
		if ( ls == 0 || ss == 0 || ss < ls * ws ) return res;

		unordered_map<string, int> map;
		vector<int> wordCnt( L.size(), 0 );
		for ( int i = 0; i < ls; ++i ) {
			if ( map.find( L[i] ) == map.end() ) {
				map[L[i]] = i;
			}
			wordCnt[map[L[i]]] ++;
		}
		vector<int> findCnt( L.size(), 0 );
		for ( int i = 0; i < ls; ++i ) {
			findCnt[i] = wordCnt[i];
		}
		deque<int> dq;
		for ( int i = 0; i < ws; ++i ) {
			//init findCnt
			clearfindCnt(  findCnt, dq );
			if ( ss - i + 1 < ls * ws ) break;
			string tmp;
			for ( int j = 0 ; i + j < ss - ws + 1;  j += ws ) {
				tmp = S.substr( i + j, ws );
				if ( map.find( tmp ) != map.end() ) {
					if ( findCnt[map[tmp]] == 0 ) { //too many duplicate
						shiftfindCntUntil(  findCnt, dq , map[tmp] );
					}
					findCnt[map[tmp]] --;
					dq.push_back( map[tmp] );
					if ( dq.size() == ls ) { //find a solution
						res.push_back( i + j + ws - ls * ws );
						shiftfindCntUntil(  findCnt, dq , dq.front() );
					}
				} else {//the word is not in
					clearfindCnt(  findCnt, dq );
				}
			}
		}
		return res;
	}

	void run( string S, vector<string> &L )
	{
		vector<int> res = findSubstring( S, L );
		cout << "res is:" << endl;
		for ( int i = 0; i < res.size(); ++i ) {
			cout << res[i] << ",";
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	string S = "barfoobarthefoobarbarfooman";
	// string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	// ["fooo","barr","wing","ding","wing"]

	vector<string> L;
	L.push_back( "foo" );
	L.push_back( "bar" );
	L.push_back( "bar" );

	// L.push_back( "fooo" );
	// L.push_back( "wing" );
	// L.push_back( "ding" );
	// L.push_back( "fooo" );
	// L.push_back( "wing" );
	Solution ss;
	ss.run( S, L );
	return 0;
}