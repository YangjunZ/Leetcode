#include <iostream>
#include <deque>

using namespace std;
// Balanced Binary Tree
// https://oj.leetcode.com/problems/balanced-binary-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};



//bug free:
// if root == NULL, is balanced ?
//
class Solution
{
public:
	bool isBalanced_core( TreeNode *root, int &depthCnt )
	{
		if ( root == NULL ) {
			depthCnt = 0;
			return true;
		}
		int l = 0, r = 0;
		if ( isBalanced_core( root->left, l ) && isBalanced_core( root->right, r ) ) {
			if ( l - 1 <= r && r <= l + 1 ) {
				depthCnt = depthCnt + 1 + ( l > r ? l : r );
				return true;
			}
		}
		return false;
	}


	bool isBalanced( TreeNode *root )
	{
		if ( root == NULL )
			return true;
		int depthCnt = 0;
		return isBalanced_core( root, depthCnt );
	}
};

int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 ), tn4(4);
	tn1.left = & tn2;
	tn2.right = & tn3;
	tn1.right = &tn4;
	Solution ss;
	cout << ss.isBalanced( &tn1 ) << endl;
	cout << "hello world" << endl;
	return 0;
}