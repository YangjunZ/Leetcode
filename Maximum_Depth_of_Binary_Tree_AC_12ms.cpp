#include <iostream>

using namespace std;
// https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxDepth(TreeNode *root) {
		if( root == NULL)
			return 0;
		int l = maxDepth( root ->left);
		int r = maxDepth( root->right);
		return 1+(l>r?l:r);
    }
};

int main(int argc, char const *argv[])
{
	cout << "hello world"<<endl;
	return 0;
}