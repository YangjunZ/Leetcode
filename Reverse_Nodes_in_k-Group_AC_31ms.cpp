#include <iostream>
#include <vector>
#include <climits>
#include <cstdarg>
using namespace std;
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

class Solution
{
public:
	ListNode *reverseKGroup( ListNode *head, int k )
	{
		if ( k <= 1 )
			return head;
		vector<ListNode *> stk;
		int cnt = 0;
		ListNode *cur = head;
		ListNode head0( -1 );
		ListNode *tail = &head0;
		ListNode *tmp;
		while ( cur ) {
			cnt = 0;
			while ( cnt < k && cur ) {
				stk.push_back( cur );
				// cout << cur->val<<endl;
				cur = cur->next;
				cnt ++;
			}
			if ( cnt == k ) {
				while ( cnt -- ) {
					tail -> next =  stk.back();
					tail = tail ->next;
					stk.pop_back();
				}
				tail->next = NULL;
			} else {
				int i = 0;
				while ( i < cnt ) {
					tail -> next =  stk[i];
					tail = tail ->next;
					i++;
				}
				tail->next = NULL;
			}
			// cout << cur->val<<endl;
		}
		return head0.next;
	}

	void print( ListNode  *head, int k )
	{
		ListNode *l = reverseKGroup( head, k );
		ListNode *cur = l;
		while ( cur ) {
			cout << cur->val << ",";
			cur = cur->next;
		}
		cout << endl;
	}
};


ListNode *generateList( int first, ... )
{
	va_list vl;
	va_start( vl, first );
	int tmp = va_arg( vl, int );
	ListNode head0( -1 );
	ListNode *cur = & head0;
	while ( tmp != INT_MIN ) {
		ListNode *tmpN = new ListNode( tmp );
		cur -> next  = tmpN;
		cur = cur->next;
		tmp = va_arg( vl, int );
	}
	va_end( vl );
	return head0.next;
}

int main( int argc, char const *argv[] )
{
	/* code */
	ListNode *h;
	h = generateList( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, INT_MAX, INT_MIN );
	Solution ss;
	// ss.print( h, 0 );
	// ss.print( h, 1 );
	ss.print( h, 10 );
	// ss.print( h, 1 );
	return 0;
}