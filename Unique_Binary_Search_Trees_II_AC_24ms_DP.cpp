#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// https://oj.leetcode.com/problems/unique-binary-search-trees-ii/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};


class Solution
{
public:
	TreeNode *clone( TreeNode *root )
	{
		if ( root == NULL )
			return NULL;
		TreeNode *copy = new TreeNode( root->val );
		copy->left = clone( root->left );
		copy->right = clone( root->right );
		return copy;
	}

	vector<TreeNode *>  generateTrees( int n )
	{
		
		vector< TreeNode *> rootVct;
		TreeNode *newNode, * tmpTree, *cur;
		
		if ( n == 0 ){
			rootVct.push_back(NULL);
			return rootVct;
		}
		rootVct.push_back( new TreeNode( 1 ) );

		for ( int i = 2; i <= n; ++i ) {
			vector<TreeNode *> tmpVct;
			for ( int j = 0; j < rootVct.size(); ++j ) {
				//add i as the new root
				newNode = new TreeNode( i );
				tmpTree = clone( rootVct[j] );

				newNode->left = tmpTree;
				tmpVct.push_back( newNode );

				//for each offspring, add i
				TreeNode *cur = rootVct[j];
				while ( cur->right ) {
					newNode = new TreeNode( i );
					newNode->left = cur->right;
					cur->right = newNode;
					tmpTree = clone( rootVct[j] );
					tmpVct.push_back( tmpTree );
					cur->right = newNode->left;
					cur = cur->right;
				}

				//add i as the last offspring
				cur->right = new TreeNode( i );
				tmpTree = clone( rootVct[j] );
				tmpVct.push_back( tmpTree );
				cur->right = NULL;
			}
			rootVct = tmpVct;
		}
		
		return rootVct;


		 // vector<TreeNode *> res(1,nullptr);
   //          for(int i = 1; i <= n; i++){
   //              vector<TreeNode *> tmp;
   //              for(int j = 0; j<res.size();j++){
   //                  TreeNode* oldroot = res[j];
   //                  TreeNode* root = new TreeNode(i);
   //                  TreeNode* target = clone(oldroot);
   //                  root->left = target;
   //                  tmp.push_back(root);

   //                  if(oldroot!=nullptr){
   //                      TreeNode* tmpold = oldroot;
   //                      while(tmpold->right!=nullptr){
   //                          TreeNode* nonroot = new TreeNode(i);
   //                          TreeNode *tright = tmpold->right;
   //                          tmpold->right = nonroot;
   //                          nonroot->left = tright;
   //                          TreeNode *target = clone(oldroot);
   //                          tmp.push_back(target);
   //                          tmpold->right = tright;
   //                          tmpold = tmpold->right;
   //                      }
   //                      tmpold->right = new TreeNode(i);
   //                      TreeNode *target = clone(oldroot);
   //                      tmp.push_back(target);
   //                      tmpold->right = nullptr;
   //                  }
   //              }
   //              res=tmp;
   //          }
   //          return res;
	}
};

void print( vector<TreeNode *> vt )
{
	for ( int i = 0; i < vt.size(); ++i ) {
		cout << "Tree " << i << ":" << endl;
		TreeNode *root = vt[i];
		if ( root == NULL ) {
			cout << "NULL" << endl;
			// return;
			continue;
		}

		deque<TreeNode *> dq;
		TreeNode *flag, *top;
		dq.push_back( root );
		flag = root;
		while ( dq.size() ) {
			top = dq.front();
			dq.pop_front();
			// if(top)
			cout << top->val << ",";
			if ( top->left ) {
				dq.push_back( top->left );
				// cout << "left" << endl;
			}
			if ( top->right ) {
				dq.push_back( top->right );
				// cout << "right" << endl;
			}

			if ( top == flag ) {
				// cout << dq.size() << endl;
				flag = dq.back();
				cout << "##";
			}
		}
		cout << endl;
	}
}

int main( int argc, char const *argv[] )
{
	Solution ss;
	// cout << ss.numTrees( 1 ) << endl;
	// cout << ss.numTrees( 2 ) << endl;
	// cout << ss.numTrees( 3 ) << endl;
	// cout << ss.numTrees( 4 ) << endl;
	// cout << ss.numTrees( 5 ) << endl;
	// cout << ss.numTrees( 6 ) << endl;
	// cout << ss.numTrees( 7 ) << endl;
	// print( ss.generateTrees( 1 ) );
	// print(ss.generateTrees( 1 ));
	print( ss.generateTrees( 2 ) );
	print( ss.generateTrees( 3 ) );
	cout << "hello world" << endl;
	return 0;
}