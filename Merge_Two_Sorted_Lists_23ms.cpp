#include <iostream>
#include <vector>

using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( NULL ) {}
};

class Solution
{
public:
	ListNode *mergeTwoLists( ListNode *l1, ListNode *l2 )
	{
		ListNode *head = new ListNode( 0 );
		ListNode *cur = head;
		while ( l1 != NULL && l2 != NULL ) {
			if ( l1->val < l2->val ) {
				cur ->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if ( l1 != NULL ) {
			cur ->next = l1;
		}
		if ( l2 != NULL ) {
			cur->next = l2;
		}
		cur = head ->next;
		delete head;
		return cur;
	}
};


int main( int argc, char const *argv[] )
{
	/* code */
	return 0;
}