#include <iostream>

using namespace std;
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
	ListNode *deleteDuplicates( ListNode *head )
	{
		if ( head == NULL || head->next == NULL )
			return head;
		// if ( head->val = head->next->val )
		//  return NULL;
		ListNode *head0 = new ListNode( 0 );
		head0 ->next = head;
		ListNode *pre = head0, *cur = head0->next, *tmp;
		bool isDuplicates = false;
		while ( cur != NULL ) {
			tmp = cur->next;
			isDuplicates = false;
			while ( tmp != NULL ) {
				if ( cur->val == tmp->val ) {
					cur->next = tmp->next;
					delete tmp;
					tmp = cur->next;
					isDuplicates = true;
				} else {
					break;
				}
			}
			if ( isDuplicates ) {
				pre->next = tmp;
				delete cur;
				cur = tmp;
				continue;
			}

			if ( cur == NULL ) {
				break;
			} else {
				pre = cur;
				cur = cur->next;
			}
		}
		head = head0->next;
		delete head0;
		return head;
	}

	void print( ListNode *head )
	{
		while ( head != NULL ) {
			cout << head->val << ",";
		}
		cout << endl;
	}
};


int main( int argc, char const *argv[] )
{
	/* code */

	return 0;
}