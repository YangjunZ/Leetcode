#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;
// https://oj.leetcode.com/problems/clone-graph/


// * Definition for undirected graph.
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode( int x ) : label( x ) {};
};

class Solution
{
public:
	UndirectedGraphNode *cloneGraph( UndirectedGraphNode *node )
	{
		//bfs, and avoid circle
		if(node == NULL)
			return node;

		std::deque<UndirectedGraphNode *> v;

		unordered_map<UndirectedGraphNode *, bool> visitMap;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
		UndirectedGraphNode *cur, * copy, *tmp;

		visitMap[node] = false;
		copy = new UndirectedGraphNode( node -> label );
		nodeMap[node] = copy;
		v.push_back( node );

		while ( v.size() > 0 ) {
			cur = v.front();
			v.pop_front();
			if ( visitMap[cur] == false ) {
				visitMap[cur] = true;
				for ( int i = 0; i < ( cur->neighbors ).size(); ++i ) {
					tmp = ( cur->neighbors )[i];
					if ( visitMap.find( tmp ) == visitMap.end() ) {
						visitMap[tmp] = false;
						v.push_back( tmp );
						copy = new UndirectedGraphNode( tmp->label );
						nodeMap[ tmp] = copy;
					}
				}

				copy = nodeMap[cur];
				for ( int i = 0; i < ( cur->neighbors ).size(); ++i ) {
					tmp = ( cur->neighbors )[i];
					( copy->neighbors ).push_back( nodeMap[ tmp] );
				}
			}


		}
		return nodeMap[node];
	}


	void print( UndirectedGraphNode *node )
	{
		//bfs, and avoid circle
		std::deque<UndirectedGraphNode *> v;
		v.push_back( node );
		unordered_map<UndirectedGraphNode *, bool> visitMap;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
		UndirectedGraphNode *cur, * copy, *tmp;
		visitMap[node] = false;
		while ( v.size() > 0 ) {
			cur = v.front();
			v.pop_front();
			cout << cur->label << ",";
			if ( visitMap[cur] == false ) {
				visitMap[cur] = true;

				// cout << cur->neighbors.size()<<endl;

				for ( int i = 0; i < ( cur->neighbors ).size(); ++i ) {
					tmp = ( cur->neighbors )[i];
					cout << tmp->label << ",";
					if ( visitMap.find( tmp ) == visitMap.end() ) {
						// cout << ( cur->neighbors )[i]->label<<endl;
						visitMap[tmp] = false;
						v.push_back( tmp );

					}
				}
				cout << " # ";
			}

		}
		cout << endl;
	}
};

int main()
{
	UndirectedGraphNode un0( 0 ), un1( 1 ), un2( 2 ), un3( 3 ), un4( 4 ), un5( 5 );
	un0.neighbors.push_back( &un1 );
	un0.neighbors.push_back( &un2 );
	un1.neighbors.push_back( &un2 );
	un2.neighbors.push_back( &un2 );

	Solution ss;
	ss.print( &un0 );
	UndirectedGraphNode *res = ss.cloneGraph( &un0 );
	ss.print( res );
	cout << "hello world" << endl;
	return 0;
}