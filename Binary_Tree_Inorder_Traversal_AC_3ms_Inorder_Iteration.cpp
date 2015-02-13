#include <iostream>
#include <vector>

using namespace std;

// https://oj.leetcode.com/problems/binary-tree-inorder-traversal/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};

class Solution
{
public:
	vector<int> inorderTraversal( TreeNode *root )
	{
		vector<TreeNode *> stack;
		vector<int> res;
		TreeNode *cur=root;
		while ( cur || stack.size() > 0 ) {
			if ( cur ) {
				stack.push_back( cur);
				cur = cur->left;
			} else {
				cur = stack.back();
				stack.pop_back();
				res.push_back( cur->val );
				cur = cur-> right;
			}
		}
		return res;
	}
};

void print( vector<int> vct )
{
	for ( int i = 0; i < vct.size(); ++i ) {
		cout << vct[i]<<",";
	}
	cout <<endl;
}
int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 ), tn4( 4 ), tn5( 5 );
	tn1.left = &tn2;
	tn2.right = & tn3;
	tn1.right = & tn4;
	tn4.left = &tn5;

	Solution ss;
	print(ss.inorderTraversal(&tn1));
	cout << "hello world" << endl;
	return 0;
}