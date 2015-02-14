#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( NULL ) {}
};
// 1->4->3->2->5->2 and x = 3,
// 1->2->2->4->3->5
//x=4, 1->3->2->2->4->5
//flag   , cur
//flag ->

class Solution
{
public:
	ListNode *partition( ListNode *head, int x )
	{
		if(head == NULL)
			return head;

		ListNode *leftHead = new ListNode( 0 );
		ListNode *rightHead = new ListNode( 0 );

		rightHead -> next = head;
		ListNode *pre, *cur, *left, *right;
		pre = rightHead;
		cur = head;
		left = leftHead;
		while ( cur ) {
			// cout << cur->val<<",";
			if ( cur->val < x ) {
				pre -> next = cur->next;
				cur ->next = left -> next;
				left -> next = cur;
				left = left->next;
				cur = pre->next;
			} else {
				pre = cur;
				cur = cur->next;
			}
		}
		left->next = rightHead->next;
		cur = leftHead -> next;
		delete leftHead, rightHead;
		return cur;
	}
};


void print(ListNode * head){
	while(head){
		cout << head->val<<",";
		head = head ->next;
	}
	cout <<endl;
}

int main( int argc, char const *argv[] )
{
	ListNode ln1(1), ln2(2), ln3(3), ln4(4), ln5(5), ln22(2);
	// ln1.next = &ln4;
	// ln4.next = &ln3;
	// ln3.next = &ln2;
	// ln2.next = &ln5;
	// ln5.next = &ln22;
	/* code */
	Solution ss;
	print(&ln1);
	print(ss.partition(&ln1, 5));
	return 0;
}