#include <iostream>
#include <climits>

using namespace std;

// https://oj.leetcode.com/problems/validate-binary-search-tree/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};


class Solution {
public:
	bool isValidBST_core(TreeNode *root, long long min, long long max){//[min, max]
		if( root == NULL)
			return true;
		if( root -> val <= min || root->val >= max)
			return false;
		return isValidBST_core( root->left, min, root->val) && isValidBST_core(root->right, root->val, max);
	}

    bool isValidBST(TreeNode *root) {
    	return  isValidBST_core(root, LLONG_MIN, LLONG_MAX);
    }
};

int main(int argc, char const *argv[])
{
	TreeNode tn1( 1 ), tn2( 2 ), tn3( 3 ), tn4( 4 ), tn5( 5 ), tn6( 6 ), tn7( 7 ), tn8( 8 ), tn9( 9 );
	tn4.left = &tn2;
	tn2.left = &tn1;
	tn2.right = &tn3;
	tn4.right = &tn7;
	tn7.left = &tn5;
	tn5.right = &tn6;
	tn7.right = &tn9;
	tn9.right = &tn8;

	Solution ss;

	cout << ss.isValidBST(&tn4)<<endl;
	cout <<"hello world"<<endl;
	return 0;
}