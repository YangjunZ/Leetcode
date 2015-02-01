#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};


//postorder traversal, record the max of (parent value + max left child value + max right child value), max child value
//to bug free: negative


class Solution
{
public:
	int postOrder( TreeNode *root, int &maxVal )
	{
		//recursion
		if ( root == NULL )
			return 0;
		int lres = postOrder( root -> left, maxVal );
		int rres = postOrder( root->right, maxVal );
		lres = lres > 0? lres: 0;
		rres = rres > 0? rres: 0;
		if( lres + root -> val + rres > maxVal)
			maxVal = lres + root -> val + rres;
		return root->val + max(lres, rres);
	}

	int maxPathSum( TreeNode *root )
	{
		if ( root == NULL )
			return 0;
		int maxVal = 0x80000000;
		postOrder(root, maxVal);
		return maxVal;
	}
};

int main( int argc, char const *argv[] )
{
	TreeNode tn1( -1 ), tn2( 2 ), tn3( -3 ), tn4( 40 ), tn5( -50 ), tn6( -6 ), tn7( 7 );
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.left = &tn4;
	tn2.right = &tn5;
	tn3.left = &tn6;
	tn3.right = &tn7;

	Solution ss;

	cout << ss.maxPathSum( &tn1 ) << endl;
	cout << "hello world" << endl;
	return 0;
}