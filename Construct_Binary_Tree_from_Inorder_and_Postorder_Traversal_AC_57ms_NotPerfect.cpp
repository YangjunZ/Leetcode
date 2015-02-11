#include <iostream>
#include <vector>
#include <deque>

using namespace std;


// https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Construct Binary Tree from Inorder and Postorder Traversal


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
	void buildTree_core( vector<int> &inorder, vector<int> &postorder, TreeNode *root, int &postIdx, int start, int end, bool isLeft )
	{
		if ( start == end || postIdx < 0 )
			return ;

		TreeNode *tmp = new TreeNode( postorder[postIdx] );
		if ( isLeft ) root->left = tmp;
		else root ->right = tmp;

		int cur = start;
		while ( cur < end && inorder[cur] != postorder[postIdx] ) cur++;

		postIdx --;
		buildTree_core( inorder, postorder, tmp, postIdx, cur + 1, end, false );
		buildTree_core( inorder, postorder, tmp, postIdx, start, cur, true );
	}


	TreeNode *buildTree( vector<int> &inorder, vector<int> &postorder )
	{
		if(inorder.size() == 0)
			return NULL;

		TreeNode *root0 = new TreeNode( 0 );
		TreeNode *root;
		int postIdx = postorder.size() -1;
		buildTree_core( inorder, postorder, root0, postIdx, 0, inorder.size(), true );
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
	vector<int> inorder = {3,5,2,4,9,7,6};
	vector<int> postorder = {3,2,4,5,7,6,9};
	Solution ss;
	print( ss.buildTree(inorder,postorder));
	cout << "hello world" << endl;
	return 0;
}