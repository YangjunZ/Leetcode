#include <iostream>
#include <vector>
#include <deque>

using namespace std;
// https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

	void buildTree_core( vector<int> &preorder, vector<int> &inorder, int &pre_idx, int start, int end, TreeNode *root, bool isLeft )
	{
		if ( pre_idx >= preorder.size() || start >= end )
			return;

		TreeNode *tn = new TreeNode( preorder[pre_idx] );
		if ( isLeft ) root->left = tn;
		else root->right = tn;


		int i = start;
		while ( i < end && inorder[i] != preorder[pre_idx] ) ++i;
		pre_idx ++;
		buildTree_core( preorder, inorder, pre_idx, start, i, tn, true );
		buildTree_core( preorder, inorder, pre_idx, i + 1, end, tn, false );
	}


	TreeNode *buildTree( vector<int> &preorder, vector<int> &inorder )
	{
		if(preorder.size() == 0)
			return NULL;

		TreeNode *root0 = new TreeNode( 0 );
		TreeNode *root;
		int pre_idx = 0;
		buildTree_core( preorder, inorder, pre_idx, 0, inorder.size(), root0, true );
		root = root0->left;
		delete root0;
		return root;
	}
};

void print( TreeNode *root )
{
	cout << " print" << endl;
	deque<TreeNode * > dq;
	TreeNode *levelEnd = root, *top;
	dq.push_back( root );
	while ( dq.size() ) {
		top = dq.front();
		dq.pop_front();
		if ( top == NULL ) {
			cout << "#" << ",";
			continue;
		}
		cout << top->val << ",";
		dq.push_back( top->left );
		dq.push_back( top->right );
		if ( top == levelEnd )
			levelEnd = dq.back();
	}
}


int main( int argc, char const *argv[] )
{
	// vector<int> preorder = {5, 6, 3, 7, 2, 9, 4, 8};
	// vector<int> inorder =  {3, 6, 7, 2, 5, 4, 9, 8};
	vector<int> preorder={1};
	vector<int> inorder{1};
	Solution ss;
	print( ss.buildTree( preorder, inorder ) );
	cout << "hello" << endl;
	return 0;
}