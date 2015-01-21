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
		std::vector<TreeNode * > parent;
		std::vector<bool> isRight;

		TreeNode *cur = root;
		isRight.push_back(false);
		// bool isRight = false;
		while (cur != NULL || stack.size() > 0) {

			while (cur == NULL && stack.size() > 0) {
				while ( parent.size() > 0 && isRight.back()==true) {
					res.push_back( parent.back()->val);
					parent.pop_back();
					isRight.pop_back();
				}
				cur = stack.back();
				parent.push_back(cur);
				stack.pop_back();
				isRight.pop_back();
				cur = cur-> right;
				isRight.push_back(true);
			}
			if (cur == NULL)
				break;
			stack.push_back( cur);
			isRight.push_back(false);
			cur = cur -> left;
			
		}
		// cout<<"hehe"<<endl;
		while ( parent.size() > 0) {
			res.push_back( parent.back()->val);
			parent.pop_back();
		}
		return res;
	}




	void test(void)
	{
		TreeNode tn(1),tn2(2), tn3(3),tn4(4);
		tn.left = &tn2;
		tn2.right = &tn3;
		// tn3.left = &tn4;
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
