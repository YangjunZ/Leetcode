#include <iostream>
#include <deque>

using namespace std;
// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/


// Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode( int x ) : val( x ), left( NULL ), right( NULL ), next( NULL ) {}
};



class Solution
{
public:
	void connect( TreeLinkNode *root )
	{
		if ( root == NULL )
			return ;

		deque < TreeLinkNode * > dq;
		TreeLinkNode *parents, *children;
		TreeLinkNode *head0 = new TreeLinkNode( 0 );
		parents = root;
		children = head0;
		while ( parents ) {
			if ( parents->left != NULL ) {
				children->next = parents->left;
                children = children->next;
			}
			if ( parents->right != NULL ) {
                children-> next= parents->right;
			    children = children->next;
            }
            if(parents ->next !=NULL)
                parents = parents->next;
            else{
                parents = head0->next;
                head0->next = NULL;
                children = head0;
            }
		}
		delete head0;
	}
};

int main( int argc, char const *argv[] )
{
	cout << "hello world" << endl;
	return 0;
}