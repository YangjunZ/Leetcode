#include <iostream>

#include <map>

using namespace std;
// https://oj.leetcode.com/problems/copy-list-with-random-pointer/
// all node can be visited by next pointer


// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode( int x ) : label( x ), next( NULL ), random( NULL ) {}
};

class Solution
{
public:
	RandomListNode *copyRandomList( RandomListNode *head )
	{
		if ( head == NULL )
			return NULL;
		RandomListNode *cur = head;
		RandomListNode *rhead0 = new RandomListNode( 0 );
		RandomListNode *rcur = rhead0;
		RandomListNode *tmp = NULL;
		std::map<RandomListNode *, RandomListNode *> map;

		while ( cur != NULL ) {
			if ( map.find( cur ) == map.end() ) {
				tmp = new RandomListNode( cur->label );
				map[cur] = tmp;
				rcur -> next = tmp;
			} else {
				rcur -> next = map[cur]; //if next -> next is a cycle.

			}
			rcur = rcur->next;

			if ( cur->random != NULL ) {
				if (  map.find( cur->random ) == map.end() ) {
					tmp = new RandomListNode( cur->random -> label );
					map[cur->random] = tmp;
					rcur->random = tmp;
				} else {
					rcur -> random = map[cur->random];
				}
			}
			cur = cur->next;
		}
		return rhead0->next;
	}

	void test( void )
	{
		RandomListNode rn1( 1 ), rn2( 2 ), rn3( 3 ), rn4( 4 ), rn5( 5 );
		rn1.next = &rn3;
		rn3.next = &rn5;
		rn1.random = &rn5;
		rn3.random = &rn1;
		rn5.random = &rn3;
		rn5.next = & rn4;
		rn4.next = & rn2;

		RandomListNode *res = copyRandomList( &rn1 );
		RandomListNode *cur = res;
		while ( cur != NULL ) {
			cout << "n:" << cur->label << ",r:";
			if ( cur->random == NULL ) cout << "null";
			else cout << cur->random->label ;
			cout << " -> ";
			cur = cur -> next;
		}

	}
};

int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}