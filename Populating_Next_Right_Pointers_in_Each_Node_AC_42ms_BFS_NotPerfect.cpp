#include <iostream>
#include <deque>

using namespace std;
// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/


// Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};



class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL)
    		return ;

        deque < TreeLinkNode* > dq;
        TreeLinkNode* top, *pre;
        TreeLinkNode* head0 = new TreeLinkNode(0);
        
        pre = head0;
        dq.push_back( NULL);
        dq.push_back( root);
        while( dq.size() > 1){
        	top = dq.front();
        	dq.pop_front();
        	if( top != NULL){
        		pre -> next = top;
        		pre = top;
        		if( top->left != NULL) 
        			dq.push_back(top->left);
        		if( top->right != NULL)
        			dq.push_back( top->right);
        	}else{
        		pre->next = NULL;
        		pre = head0;
        		dq.push_back(NULL);
        	}
        }
        delete head0;
    }
};

int main(int argc, char const *argv[])
{
	cout << "hello world"<<endl;
	return 0;
}