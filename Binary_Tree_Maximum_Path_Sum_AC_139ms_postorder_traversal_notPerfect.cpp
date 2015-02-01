#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};


//postorder traversal, record the max of (parent value + max left child value + max right child value), max child value
//to bug free: negative

class Solution
{
public:
	int maxPathSum( TreeNode *root )
	{
		if ( root == NULL )
			return 0;

		vector< TreeNode *> stack;
		unordered_map< TreeNode *, pair<int, int>> valMap; //pair, first, max value of  the path from left child to right child, second, max value of the path from child to parent
		unordered_set< TreeNode *> visited;
		TreeNode *top;

		valMap[NULL] = make_pair( 0, 0 );
		visited.insert( NULL );
		stack.push_back( root );
		int maxVal = 0x80000000;
		while ( stack.size() > 0 ) {
			top = stack.back();
			if ( visited.find( top->left ) != visited.end() && visited.find( top->right ) != visited.end() ) {
				//path: l->p->r
				int first = top-> val + valMap[top->left].second + valMap[top->right].second;
				
				int second = top->val + valMap[top->right].second;//p->r
				int tmp = valMap[top->left].second + top->val;//l->p
				second = second > tmp? second: tmp; // p->r or l->p
				second = second > top->val ? second: top->val; //p->r or l->p or p
				
				valMap[top]  = make_pair( first, second );
				maxVal = maxVal > first ? maxVal : first;
				maxVal = maxVal > second ? maxVal : second;
				// cout<< top-> val<<":"<<first <<","<< second <<endl;
				visited.insert( top );
				stack.pop_back();
				continue;
			}
			if ( visited.find( top->right ) == visited.end() ) {
				stack.push_back( top->right );
			}
			if ( visited.find( top->left ) == visited.end() ) {
				stack.push_back( top->left );
			}

		}
		return maxVal;
	}
};

int main( int argc, char const *argv[] )
{
	TreeNode tn1( -1 ), tn2( 2 ), tn3( -3 ), tn4( 40 ), tn5( -50 ), tn6( -6 ), tn7( 7 );
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.left = &tn4;
	tn2.right = &tn5;
	tn3.left = &tn6;
	tn3.right = &tn7;

	Solution ss;

	cout << ss.maxPathSum( &tn1 ) << endl;
	cout << "hello world" << endl;
	return 0;
}