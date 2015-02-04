#include <iostream>
#include <deque>

using namespace std;

// https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};
class Solution
{
public:
	int minDepth( TreeNode *root )
	{
		if ( root == NULL )
			return 0;

		deque< TreeNode * > dq;
		int depthCnt = 1;
		TreeNode *top;

		dq.push_back( root );
		dq.push_back( NULL );
		while ( dq.size() > 1 ) {
			top = dq.front();
			dq.pop_front();
			if ( top == NULL ) {
				depthCnt ++;
				dq.push_back( NULL );
				continue;
			}

			if ( top->left == NULL && top->right == NULL )
				return depthCnt;

			if ( top->left )
				dq.push_back( top->left );
			if ( top->right )
				dq.push_back( top->right );
		}

	}
};

int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 );
	tn1.left = & tn2;
	tn2.right = & tn3;
	Solution ss;
	cout << ss.minDepth( &tn1 ) << endl;
	cout << "hello world" << endl;
	return 0;
}