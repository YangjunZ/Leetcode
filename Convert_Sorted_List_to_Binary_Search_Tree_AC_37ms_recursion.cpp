#include <iostream>
#include <deque>
#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( NULL ) {}
};

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
	void dfs_core( TreeNode *root, ListNode *start, ListNode *end, bool isLeft )
	{
		ListNode *cur = start, *tmp = start;
		if ( start == end || cur == NULL )
			return;

		while ( tmp != end && tmp->next != end ) {
			tmp = tmp->next->next;
			cur = cur->next;
		}
		TreeNode *mid = new TreeNode( cur->val );
		if ( isLeft )
			root->left = mid;
		else
			root->right = mid;
		dfs_core( mid, start, cur, true );
		dfs_core( mid, cur->next, end, false );
	}

	TreeNode *sortedListToBST( ListNode *head )
	{
		TreeNode *root0 = new TreeNode( 0 );
		TreeNode *root;
		dfs_core( root0, head, NULL, true );
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
	vector<ListNode> v( 9, ListNode( 0 ) );
	for ( int i = 0; i < v.size() - 1; ++i ) {
		v[i].val = i;
		v[i].next = &v[i + 1];
	}
	v[v.size() - 1] = v.size() - 1;
	Solution ss;

	print( ss.sortedListToBST( &v[0] ) );

	cout << "hello world" << endl;
	return 0;
}