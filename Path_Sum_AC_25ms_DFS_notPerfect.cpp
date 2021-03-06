#include <iostream>
#include <vector>
#include <utility>

using namespace std;
// https://oj.leetcode.com/problems/path-sum/


// Definition for binary tree
//bug free, negative

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};

class Solution
{
public:
	bool hasPathSum( TreeNode *root, int sum )
	{
		if ( root == NULL )
			return false;

		vector< pair<TreeNode *, int> > stack;
		TreeNode *cur;
		pair<TreeNode *, int> top;
		int tmp = 0;
		stack.push_back( make_pair( root, 0 ) );

		while ( stack.size() ) {
			top  = stack.back();
			stack.pop_back();
			cur = top.first;
			tmp = top.second + cur->val;

			if ( tmp  == sum && cur ->right == NULL && cur->left == NULL )
				return true;

			// if ( (sum > 0 && tmp  > sum) || (sum) )
			//  continue;

			if ( cur->right )
				stack.push_back( make_pair( cur->right, tmp ) );

			if ( cur->left )
				stack.push_back( make_pair( cur->left, tmp ) );
		}
		return false;
	}
};

int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 );
	tn1.right = &tn2;
	tn2.left = &tn3;
	Solution ss;
	cout << ss.hasPathSum( &tn1, 6 ) << endl;;
	cout << "hello world" << endl;
	return 0;
}