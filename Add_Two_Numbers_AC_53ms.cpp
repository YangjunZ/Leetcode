#include <iostream>

using namespace std;

// https://oj.leetcode.com/problems/add-two-numbers/
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( NULL ) {}
};


class Solution
{
public:
	ListNode *addTwoNumbers( ListNode *l1, ListNode *l2 )
	{
		if ( l1 == NULL && l2 == NULL )
			return NULL;

		int carry = 0, tmp;
		ListNode *cur1 = l1;
		ListNode *cur2 = l2;
		ListNode *pre1 = NULL;
		while ( cur1 && cur2 ) {
			tmp = cur1->val + cur2->val + carry;
			cur1->val = tmp % 10;
			carry = tmp / 10;
			pre1 = cur1;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}

		if ( cur2 ) {
			if ( pre1 )
				pre1 ->next = cur2;
			cur1 = cur2;
		}

		while ( cur1 ) {
			tmp = cur1->val + carry;
			cur1->val = tmp % 10;
			carry = tmp / 10;
			pre1 = cur1;
			cur1 = cur1->next;
		}
		if ( carry > 0 ) {
			ListNode *tail = new ListNode( carry );
			pre1->next = tail;
		}
		return l1;
	}
};

int main( int argc, char const *argv[] )
{
	ListNode ln1( 1 ), ln2( 2 ), ln3( 3 ), ln4( 4 ), ln5( 5 );
	ListNode ln_1( 1 ), ln_2( 2 ), ln_3( 3 ), ln_4( 4 ), ln_5( 5 );

	return 0;
}