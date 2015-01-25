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
		RandomListNode *copy = NULL, *tmp = NULL;

		while ( cur != NULL ) {
			copy = new RandomListNode( cur->label );
			tmp = cur -> next;
			cur->next = copy;
			copy -> next = tmp;
			cur = tmp;
		}
		cur = head;
		while( cur != NULL){
			copy = cur->next;
			copy->random = cur->random;
			if(copy->random != NULL){
				copy->random = cur->random->next;
			}
			cur = copy -> next;
		}


		RandomListNode *copyHead0 =  new RandomListNode( 0 );
		tmp = copyHead0;
		cur = head;
		while ( cur !=  NULL ) {
			tmp -> next = cur -> next;
			tmp = tmp->next;			
			cur->next = cur->next -> next;
			cur = cur->next;
		}
		tmp = copyHead0 -> next;
		delete copyHead0;
		return tmp;
	}

	void print( RandomListNode *cur )
	{
		while ( cur != NULL ) {
			cout << cur << ".n:" << cur->label << ",r:";
			if ( cur->random == NULL ) cout << "null";
			else cout << cur->random->label ;
			cout << " -> ";
			cur = cur -> next;
		}
		cout << endl;
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

		print( &rn1 );
		RandomListNode *res = copyRandomList( &rn1 );
		// RandomListNode *cur = res;
		print( res );
		// while ( cur != NULL ) {
		//  cout << "n:" << cur->label << ",r:";
		//  if ( cur->random == NULL ) cout << "null";
		//  else cout << cur->random->label ;
		//  cout << " -> ";
		//  cur = cur -> next;
		// }

	}

};

int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}