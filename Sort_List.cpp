#include <iostream>
// #include <>

using namespace std;
// https://oj.leetcode.com/problems/sort-list/
// Sort a linked list in O(n log n) time using constant space complexity.


//merge sort,
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



class Solution
{
public:

	ListNode *mergeSort(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *left = head;
		ListNode *right = head;
		ListNode *pre = head;
		//divide into two part
		while ( right != NULL && right->next != NULL) {
			right = right->next ->next;
			pre = left; //in case the list length is 2,
			left = left -> next;
		}
		pre -> next = NULL;
		right = left;
		left = head;
		left = mergeSort( left);
		right = mergeSort( right);
		return merge(left, right);
	}


	ListNode *merge(ListNode *left, ListNode *right)
	{
		ListNode *head = new ListNode(0);
		ListNode *cur = head;
		while (left != NULL && right != NULL) {
			if (left->val <= right->val) {
				cur->next = left;
				left = left->next;
				cur = cur->next;
			} else {
				cur->next = right;
				right = right ->next;
				cur = cur->next;
			}
		}
		if (left != NULL) {
			cur -> next = left;
		}

		if (right != NULL) {
			cur->next = right;
		}
		cur = head->next;
		delete head;
		return cur;
	}


	ListNode *sortList(ListNode *head)
	{
		//headptr, first,
		return mergeSort( head);

	}
};



int main()
{
	Solution ss;

	cout << "hello world" << endl;

	return 0;
}