#include <iostream>
#include <vector>

using namespace std;
// Flatten Binary Tree to Linked List
// https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/


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
	void flatten( TreeNode *root )
	{
		vector< TreeNode *> stack;
		TreeNode *top, *cur;
		TreeNode *head0 = new TreeNode( 0 );
		cur = head0;
		stack.push_back( root );
		while ( stack.size() ) {
			top = stack.back();
			stack.pop_back();
			if ( top ) {
				if ( top->right )
					stack.push_back( top->right );
				if ( top->left )
					stack.push_back( top->left );
				top->left = NULL; //it will be runtime error without this.
				cur->right = top;
				cur = top;

				// cout << top->val<<" ";
			}
		}
		if ( cur )
			cur -> right = NULL;
		delete head0;
	}
};

void print( TreeNode *cur )
{
	while ( cur ) {
		cout << cur->val << " ";
		cur = cur->right;
	}
	cout << endl;
}

int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 );
	tn1.right = &tn2;
	// tn2.left = &tn3;
	Solution ss;
	ss.flatten( &tn1 );
	print( &tn1 );
	cout << "hello world" << endl;
	return 0;
}