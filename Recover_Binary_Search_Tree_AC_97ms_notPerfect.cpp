#include <iostream>
#include <climits>

using namespace std;

// https://oj.leetcode.com/problems/recover-binary-search-tree/

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};
//morris traversal
//bug free: negative, same val,
// swap child with ancestor , or swap child with others
// how to find the error node, [min, max]
//      5
//   3      8
//  2  4  6    9
// 1       7

//      5
//   3      8
//  2  4  6    9
// 1       7


class Solution
{
public:

	// TreeNode *first = NULL;
	//    TreeNode *second = NULL;
	//    TreeNode *previous = NULL;

	//    void recoverTree(TreeNode *root) {
	//        if (!root) return;
	//        previous = new TreeNode(INT_MIN);

	//        morris_inorder(root);
	//        int t = first->val;
	//        first->val = second->val;
	//        second->val = t;
	//    }

	//    void morris_inorder(TreeNode *root) {
	//        TreeNode *cur = root, *pre = NULL;

	//        while (cur) {
	//            if (cur->left == NULL) {
	//                if (cur->val <= previous->val && !first) first = previous;
	//                if (cur->val <= previous->val && first) second = cur;
	//                previous = cur;
	//                cur = cur->right;
	//            }
	//            else {
	//                // find the predecessor
	//                pre = cur->left;
	//                while (pre->right && pre->right != cur)
	//                    pre = pre->right;

	//                if (pre->right == NULL) {
	//                    // set the backtrace link
	//                    pre->right = cur;
	//                    cur = cur->left;
	//                }
	//                else {
	//                    if (cur->val <= previous->val && !first) first = previous;
	//                    if (cur->val <= previous->val && first) second = cur;
	//                    previous = cur;
	//                    pre->right = NULL;
	//                    cur = cur->right;
	//                }
	//            }
	//        }
	//    }

	void morris_traversal( TreeNode *root )
	{
		TreeNode *cur = root;
		TreeNode *pre = root;
		while ( cur ) {
			if ( cur->left ) {
				// pre = cur;
				pre = cur->left;
				while ( pre -> right && pre ->right != cur ) {
					pre = pre->right;
				}
				if ( pre->right ) { // parent
					cout << cur->val << ",";
					pre->right = NULL; //discard predecessor
					cur = cur->right;
				} else {
					pre->right = cur;
					cur = cur ->left;
				}
			} else {
				cout << cur->val << ",";
				cur = cur->right;
			}
		}
	}

	void recoverTree( TreeNode *root )
	{
		TreeNode *cur = root, *first, *second, *pre;
		TreeNode *head0 = new TreeNode( INT_MIN );
		cout << head0->val << endl;
		TreeNode *previous = head0;
		first = NULL;
		while ( cur ) {
			if ( cur->left ) {
				// pre = cur;
				pre = cur->left;
				while ( pre -> right && pre ->right != cur ) {
					pre = pre->right;
				}
				if ( pre->right ) { // parent
					// cout << cur->val<<",";
					if ( cur->val <= previous->val && first == NULL ) {
						// cout << "1find it " << previous->val << endl;
						first = previous;
					}
					if ( cur->val <= previous->val && first != NULL ) {
						second = cur;
					}
					pre->right = NULL; //discard predecessor
					previous = cur;
					cur = cur->right;

				} else {
					pre->right = cur;
					cur = cur ->left;
				}
			} else {
				// cout << cur->val<<",";
				if ( cur->val <= previous->val && first == NULL ) {
					first = previous;
					// cout << "find it " << previous->val << endl;
				}
				if ( cur->val <= previous->val && first != NULL ) {
					second = cur;
				}
				previous = cur;
				cur = cur->right;
			}
		}
		int tmp = first ->val;
		first->val = second ->val;
		second ->val = tmp;
	}
};

int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 ), tn4( 4 ), tn5( 5 ), tn6( 6 ), tn7( 7 ), tn8( 8 ), tn9( 9 );
	// tn4.left = &tn2;
	// tn2.left = &tn1;
	// tn2.right = &tn3;
	// tn4.right = &tn7;
	// tn7.left = &tn5;
	// tn5.right = &tn6;
	// tn7.right = &tn9;
	// tn9.left = &tn8;

	// tn2.val = 5;
	// tn5.val = 2;

	// tn1.left = & tn2;
	tn2.left = &tn1;
	tn2.right = &tn3;
	tn1.val = 3;
	tn3.val = 1;

	Solution ss;

	ss.morris_traversal( &tn2 );
	cout << endl;
	ss.recoverTree( &tn2 );

	ss.morris_traversal( &tn2 );
	cout << "hello world" << endl;
	return 0;
}