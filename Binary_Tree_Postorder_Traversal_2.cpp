#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/binary-tree-postorder-traversal/

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
	vector<int> postorderTraversal(TreeNode *root)
	{
		std::vector<int> res;
		if (root == NULL) {
			return res;
		}

		std::vector<TreeNode * > stack;
		TreeNode *cur = root;

		while (cur != NULL || stack.size() > 0) {
			while (cur == NULL && stack.size() > 0) {
				cur = stack.back();
				stack.pop_back();
				cur = cur->left;
			}
			if (cur == NULL)
				break;
			res.push_back(cur->val);
			stack.push_back( cur);
			cur = cur -> right;	
		}
		std::vector<int> rres;
		for(std::vector<int>::reverse_iterator ri = res.rbegin(); ri != res.rend(); ri++){
			rres.push_back( *ri);
		}
		return rres;
	}




	void test(void)
	{
		TreeNode tn(1),tn2(2), tn3(3),tn4(4);
		tn.left = &tn2;
		tn2.right = &tn3;
		tn.right = &tn4;
		std::vector<int> v = postorderTraversal(&tn);
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ", ";
		cout << endl;
	}
};


int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}
