#include <iostream>
#include <vector>
#include <deque>

using namespace std;
// https://oj.leetcode.com/problems/symmetric-tree/

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
	bool isSymmetric( TreeNode *root )
	{
		if ( root == NULL )
			return true;
		deque< TreeNode *> dq;
		TreeNode *cur;
		cur = root;
		dq.push_back( root );
		vector<int> v;
		vector<bool> vb;
		int flag = 1;
		int cnt = 0;
		int nextCnt = 0;
		while ( dq.size() ) {
			cur = dq.front();
			cnt ++;
			if ( cur ) {
				nextCnt ++;
				v.push_back( cur->val );
				vb.push_back( true );
			} else {
				v.push_back( 0 );
				vb.push_back( false );
			}
			// cout << v.back() << " ";
			dq.pop_front();
			// if ( cur->left )
			if ( cur ) {
				dq.push_back( cur->left );
				dq.push_back( cur->right );
			}
			if ( cnt == flag ) {
				// flag = flag << 1;
				int i = 0, j = v.size() - 1;
				while ( i <= j && v[i] == v[j] ){
					++i;
					--j;
				}
				if ( i <= j ) return false;
				v.clear();

				i = 0; j = vb.size() - 1;
				while ( i <= j && vb[i] == vb[j] ){
					++i;
					--j;
				}
				if ( i <= j ) return false;
				vb.clear();
				flag = nextCnt << 1;
				nextCnt = 0;
				cnt = 0;
			}
		}
		return true;
	}
};


int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 2 ), tn4( 4 ), tn5( 4 ), tn6( 6 );
	// tn1.left = & tn2;
	// tn2.right = &tn3;
	// tn1.right = &tn4;
	// tn4.right = &tn5;
	// tn4.left = &tn6;
	tn1.left = &tn2;
	// tn1.right = &tn3;
	// tn2.right = &tn4;
	// tn3.right = &tn5;

	Solution ss;
	cout << ss.isSymmetric( &tn1 ) << endl;
	cout << "hello world" << endl;
	return 0;
}