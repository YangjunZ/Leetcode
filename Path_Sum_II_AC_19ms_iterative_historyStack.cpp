#include <iostream>
#include <vector>
#include <utility>

using namespace std;
// https://oj.leetcode.com/problems/path-sum-ii/


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
	vector<vector<int> > pathSum( TreeNode *root, int sum )
	{

		vector< vector<int>> res;
		if ( root == NULL )
			return res;

		vector< TreeNode *> stack;
		vector< TreeNode *> history;
		vector< int> sumStack;
		TreeNode *cur;
		TreeNode *pre;
		int tmp = 0;
		stack.push_back( root );
		sumStack.push_back( 0 );

		while ( stack.size() ) {
			cur  = stack.back();
			stack.pop_back();

			while ( history.size() > 0 ) {
				pre = history.back();
				if ( pre->left == cur || pre->right == cur )
					break;
				history.pop_back();
			}
			tmp = sumStack.back();
			sumStack.pop_back();

			tmp = tmp + cur->val;
			if ( tmp  == sum && cur ->right == NULL && cur->left == NULL ) {
				vector< int> tmpv;
				for ( int i = 0; i < history.size(); ++i ) {
					tmpv.push_back( history[i]->val );
				}
				tmpv.push_back(cur->val);
				res.push_back( tmpv );
				continue;
			}

			history.push_back( cur );
			if ( cur->right ) {
				stack.push_back( cur->right );
				sumStack.push_back( tmp );
			}

			if ( cur->left ) {
				stack.push_back(  cur->left );
				sumStack.push_back( tmp );
			}
		}
		return res;
	}
};

void print( vector< vector<int>> vv )
{
	cout << "["<<endl;
	for ( int i = 0; i < vv.size(); ++i ) {
		cout << "[";
		for ( int j = 0; j < vv[i].size(); ++j )
			cout << vv[i][j] << ",";
		cout << "]," << endl;
	}
	cout << "]" << endl;
}

int main( int argc, char const *argv[] )
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 ), tn4(2), tn5(3);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.right = &tn5;
	tn3.left = &tn4;

	Solution ss;
	print(ss.pathSum( &tn1, 6 ));
	cout << "hello world" << endl;
	return 0;
}