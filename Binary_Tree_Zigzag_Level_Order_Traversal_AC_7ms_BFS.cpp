#include <iostream>
#include <vector>
#include <deque>

using namespace std;


// https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};


class Solution
{
public:
	vector<vector<int> > zigzagLevelOrder( TreeNode *root )
	{
		vector< vector<int> > res;
		if ( root == NULL )
			return res;
		deque< TreeNode *> dq;

		TreeNode *cur, * flag;
		flag = cur = root;
		dq.push_back( root );
		vector<int> v;
		while ( dq.size() ) {
			cur = dq.front();
			v.push_back( cur->val );
			dq.pop_front();
			if ( cur->left )
				dq.push_back( cur->left );
			if ( cur ->right )
				dq.push_back( cur->right );
			if ( cur == flag ) {
				flag = dq.back();
				res.push_back( v );
				v.clear();
			}
		}

		for ( int i = 1; i < res.size(); i += 2 ) {
			vector<int> tmp;
			for ( int j = res[i].size() - 1; j >= 0; --j )
				tmp.push_back( res[i][j] );
			res[i] = tmp;
		}
		return res;

	}
};


void print( vector< vector<int>> vv )
{
	cout << "[" << endl;
	for ( int i = 0; i < vv.size(); ++i ) {
		cout << "[";
		for ( int j = 0; j < vv[i].size(); ++j )
			cout << vv[i][j] << ",";
		cout << "]," << endl;
	}
	cout << "]" << endl;
}
int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 ), tn4( 4 ), tn5( 5 ), tn6( 6 );
	tn1.left = & tn2;
	tn2.right = &tn3;
	tn1.right = &tn4;
	tn4.right = &tn5;
	tn4.left = &tn6;
	Solution ss;
	print( ss.zigzagLevelOrder( &tn1 ) );
	cout << "hello world" << endl;
	return 0;
}