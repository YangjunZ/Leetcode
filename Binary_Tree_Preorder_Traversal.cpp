#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// Note: Recursive solution is trivial, could you do it iteratively?


//AC for 4ms

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		std::vector<int> res;
		if(root == NULL){
			return res;
		}

		std::vector<TreeNode * > stack;

		TreeNode *cur = root;
		while (cur != NULL || stack.size() > 0) {
			while(cur == NULL && stack.size() > 0){
				cur = stack.back();
				stack.pop_back();				
				cur = cur-> right;
			}
			if(cur == NULL) 
				break;
			res.push_back( cur->val);
			stack.push_back( cur);			
			cur = cur -> left;
		}
		return res;
	}

	void test(void){
		TreeNode tn(1);
		std::vector<int> v = preorderTraversal(&tn);
		for(int i=0; i< v.size();i++)
			cout<< v[i]<<", ";
		cout <<endl;
	}
};


int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}