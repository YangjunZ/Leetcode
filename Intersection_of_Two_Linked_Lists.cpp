#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
// map record the node address of list a, than search the node address in node b


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
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	void getEnd(ListNode *h, ListNode **pre, int *size)
	{
		ListNode *cur = h;
		*pre = NULL;
		*size = 0;
		while ( cur != NULL) {
			// *curA -> val;
			*size = *size + 1;
			*pre = cur;
			cur = cur -> next;

		}
		// *size = cnt;
	}

	ListNode *getNode(ListNode *h, int index)
	{
		ListNode *cur = h;
		int cnt = 0;
		while ( cur != NULL) {
			if (cnt == index) {
				return cur;
			}
			cur = cur -> next;
			cnt ++;
		}
		return cur;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{


		ListNode *endA = NULL;
		int asize = 0;
		getEnd(headA, &endA, &asize);


		ListNode *endB = NULL;
		int bsize = 0;
		getEnd(headB, &endB, &bsize);
		if ( endA == endB) {
			// cout << "intersection" << " asize:" << asize << " bsize:" << bsize << endl;
			if ( asize == 1) return endA;
			if ( bsize == 1) return endB;

			int aindex = asize - 2;
			int bindex = bsize - 2;
			ListNode *res = endA;
			while (aindex >= 0 && bindex >= 0) {
				ListNode *resA = getNode(headA, aindex);
				ListNode *resB = getNode(headB, bindex);
				if ( resA == resB) {
					res = resA;
					aindex --;
					bindex --;
				} else
					break;
			}
			return res;
		}

		// cout << "Not intersection" << endl;
		return NULL;
	}

	//Memory Limit Exceeded, time O(n), memory O(n)
	ListNode *getIntersectionNode_Map(ListNode *headA, ListNode *headB)
	{
		std::map<ListNode *, int> addresMap;
		ListNode *curA = headA;
		while ( curA != NULL) {
			addresMap[curA] = curA -> val;
			// *curA -> val;
			curA = curA -> next;
		}
		// cout <<"addresMap size:"<< addresMap.size()<<endl;
		ListNode *curB = headB;
		while (curB != NULL) {
			if ( addresMap.find(curB) != addresMap.end()) {
				break;
			}
			curB = curB->next;
		}

		return curB;
	}

	void print(string str, ListNode *h)
	{
		ListNode *cur = h;
		cout << str << ":";
		while (cur != NULL) {
			cout << hex << cur << ":" << oct << cur->val << "-> ";
			cur = cur -> next;
		}
		cout << "end" << endl;
	}
	void test(int *a, int asize, int *b, int bsize, int *c, int csize)
	{
		// return 0;
		if ( asize + csize < 1 || bsize + csize < 1 )
			return;

		ListNode *cc = NULL;
		ListNode *pre;
		if ( csize > 0) {
			cc = new ListNode(c[0]);
			pre = cc;
			for ( int i = 1; i < csize; i++) {
				ListNode *cur = new ListNode(c[i]);
				pre->next = cur;
				pre = cur;
			}
		}

		ListNode *aa;
		if (asize > 0) {
			aa = new ListNode(a[0]);
			pre = aa;
			for (int i = 1; i < asize; i++) {
				ListNode *cur = new ListNode(a[i]);
				pre -> next = cur;
				pre = cur;
			}
			pre -> next = cc;
		} else
			aa = cc;



		ListNode *bb;
		if ( bsize > 0) {
			bb = new ListNode(b[0]);
			pre = bb;
			for (int i = 1; i < bsize; i++) {
				ListNode *cur = new ListNode(b[i]);
				pre -> next = cur;
				pre = cur;
			}
			pre ->next = cc;
		} else
			bb = cc;

		print("aa", aa);
		print("bb", bb);
		print("cc", cc);
		ListNode *res = getIntersectionNode( aa, bb);
		if (res == NULL) {
			cout << "res:" << "NULL" << endl;
		} else {
			cout << "res:" << endl;
			print("intersection", res);
		}
		// ListNode()
	}
};

int main()
{
	int a[] = {1, 3, 5};
	int b[] = {12, 89};
	int c[] = {1, 9};
	Solution ss;
	ss.test(a, sizeof(a) / sizeof(int), b, sizeof(b) / sizeof(int), c, sizeof(c) / sizeof(int));

	return 0;
}