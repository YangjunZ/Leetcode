#include <iostream>

using namespace std;

// Remove Nth Node From End of List


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( NULL ) {}
};
//1,2,3,4,5,6
class Solution
{
public:
	ListNode *removeNthFromEnd( ListNode *head, int n )
	{
		int length = 0;
		ListNode *cur = head;
		while ( cur != NULL ) {
			length ++;
			cur = cur->next;
		}
		int cnt = length - n - 1;
		cur = head;
		if ( cnt == -1 ) {
			return cur->next;
		}
		
		while ( cnt-- ) cur = cur->next;

		cur ->next = cur->next ->next;
		return head;

	}
	void print( ListNode *head, int n )
	{
		ListNode *cur = head;
		while ( cur != NULL ) {
			cout << cur->val << ",";
			cur = cur->next;
		}
		cout << endl;
		cur = removeNthFromEnd( head, n );
		while ( cur != NULL ) {
			cout << cur->val << ",";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main( int argc, char const *argv[] )
{
	/* code */
	Solution ss;
	ListNode ln1( 1 ), ln2( 2 ), ln3( 3 ), ln4( 4 );
	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ss.print( &ln1, 3 );
	return 0;
}