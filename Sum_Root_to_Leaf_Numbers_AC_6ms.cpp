#include <iostream>

#include <vector>
#include <utility>
using namespace std;
// https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/using namespace std;


 // * Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    int sumNumbers(TreeNode *root) {
    	if( root == NULL)
    		return 0;
        int total_sum = 0;
        int sum = 0;
        vector< pair<TreeNode*, int> > stack;
        TreeNode * curNode;
        stack.push_back( make_pair(root, 0));
    	pair< TreeNode*, int> cur;

    	while( stack.size() >0){
    		cur = stack.back();
    		stack.pop_back();
    		curNode = cur.first;
    		sum = cur.second*10 + curNode->val;
    		if( curNode -> right != NULL){
    			stack.push_back( make_pair(curNode->right, sum));
    		}
    		if( curNode -> left != NULL){
    			stack.push_back( make_pair(curNode->left, sum));
    		}

    		if( curNode->left == NULL && curNode-> right == NULL){
    			total_sum = total_sum + sum;
    		}
    	}
    	return total_sum;
    }
};

int main()
{
	TreeNode n1(1), n2(2), n3(3);
	n1.left =  & n2;
	n1.right = &n3;
	Solution ss;
	cout << ss.sumNumbers( &n1) <<endl;
	cout << "hello world"<<endl;
	return 0;
}