#include <iostream>
#include <vector>
#include <cstdarg>
#include <climits>
using namespace std;
// https://leetcode.com/problems/swap-nodes-in-pairs/

struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( NULL ) {}
};

class Solution
{
public:
	ListNode *swapPairs( ListNode *head )
	{
		if ( head == NULL || head->next == NULL )
			return head;
		ListNode head0( -1 );
		ListNode *cur = &head0;
		ListNode *p1, *p2;
		p1 = head; p2 = p1->next;
		while ( p1 && p2 ) {
			p1->next = p2->next;
			p2 ->next = p1;
			cur->next = p2;
			cur = p1;
			p1 = p1->next;
			if ( p1 )
				p2 = p1->next;
			else
				break;
		}
		return head0.next;
	}

	void print( ListNode *head )
	{
		ListNode *  cur = swapPairs( head );
		while ( cur ) {
			cout << cur->val << ",";
			cur = cur->next;
		}
		cout << endl;
	}
};

ListNode *generateList( int first, ... )
{
	ListNode head0( -1 );
	ListNode *cur = &head0;
	va_list vl;
	int tmp;
	va_start( vl, first );
	tmp = va_arg( vl, int );
	while ( tmp != INT_MIN ) {
		// cout << tmp<<".";
		ListNode *tmpN = new ListNode( tmp );

		cur->next = tmpN;
		cur = tmpN;
		tmp = va_arg( vl, int );
	}
	va_end( vl );
	return head0.next;
}

int main( int argc, char const *argv[] )
{
	/* code */
	ListNode * h;
	h = generateList(0,1,2,3,4,5,6,7,8,9,0,INT_MAX, INT_MIN);
	Solution ss;
	ss.print(h);
	return 0;
}