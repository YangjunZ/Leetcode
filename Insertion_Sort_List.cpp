#include <iostream>

using namespace std;
// https://oj.leetcode.com/problems/insertion-sort-list/
// Sort a linked list using insertion sort.




// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *insertionSort(ListNode *head)
	{
		if ( head == NULL || head->next == NULL)
			return head;

		ListNode *head0 = new ListNode(0);
		ListNode *token = head;
		ListNode *pre, *cur;

		while (token != NULL) {
			pre = head0;
			cur = head0->next;
			// while(pre);
			while (cur != NULL && pre != NULL) {
				if (token -> val < cur->val) {
					break;
				}
				pre = cur;
				cur = cur -> next;
			}
			pre -> next = token;
			token = token -> next;
			if (cur == NULL) {
				pre -> next -> next = NULL;
			} else {
				pre -> next -> next = cur;
			}
		}
		head = head0->next;
		delete head0;
		return head;

	}
	ListNode *insertionSortList(ListNode *head)
	{
		return insertionSort( head);
	}
};



int testCase[] = { -84, 142, 41, -17, -71, 170, 186, 183, -21, -76, 76, 10, 29, 81, 112, -39, -6, -43, 58, 41, 111, 33, 69, 97, -38, 82, -44, -7, 99, 135, 42, 150, 149, -21, -30, 164, 153, 92, 180, -61, 99, -81, 147, 109, 34, 98, 14, 178, 105, 5, 43, 46, 40, -37, 23, 16, 123, -53, 34, 192, -73, 94, 39, 96, 115, 88, -31, -96, 106, 131, 64, 189, -91, -34, -56, -22, 105, 104, 22, -31, -43, 90, 96, 65, -85, 184, 85, 90, 118, 152, -31, 161, 22, 104, -85, 160, 120, -31, 144, 115};
int main()
{
	Solution ss;
	ListNode *head0 = new ListNode(0);
	ListNode *pre = head0;
	ListNode *cur = head0;
	int size = sizeof(testCase) / sizeof(int);
	cout << "size:" << size << endl;
	for (int i = 0; i < size; i++) {
		pre = cur;
		cur = cur->next;
		cur = new ListNode(testCase[i]);
		pre ->next = cur;
	}
	cur = head0->next;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	cur = ss.insertionSortList(head0->next);
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	cout << "hello world" << endl;
	return 0;
}