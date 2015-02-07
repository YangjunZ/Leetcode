#include <iostream>
#include <vector>
#include <deque>

using namespace std;
// https://oj.leetcode.com/problems/symmetric-tree/

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
	bool dfs( TreeNode *p, TreeNode *q )
	{
		if  ( p == NULL || q == NULL ) {
			if ( p == q )
				return true;
			else
				return false;
		}
		cout << p->val <<" "<<q->val<<endl;
		if ( p->val == q->val ) {
			return dfs( p->left, q->left ) && dfs( p->right, q->right );
		}
		return false;
	}

	bool isSameTree ( TreeNode *p, TreeNode *q )
	{
		return dfs( p, q );
	}
};


int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 2 ), tn4( 4 ), tn5( 4 ), tn6( 6 );
	TreeNode tt1( 1 ), tt2( 2 ), tt3( 2 ), tt4( 4 ), tt5( 4 ), tt6( 6 );
	// tn1.left = & tn2;
	// tn2.right = &tn3;
	// tn1.right = &tn4;
	// tn4.right = &tn5;
	// tn4.left = &tn6;
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.right = &tn4;
	tn3.right = &tn5;

	tt1.left = &tt2;
	tt1.right = &tt3;
	tn2.right = &tt4;
	tn3.right = &tt5;

	Solution ss;
	cout << ss.isSameTree( &tn1, &tt1 ) << endl;
	cout << "hello world" << endl;
	return 0;
}