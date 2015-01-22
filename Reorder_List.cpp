#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	void reorderList(ListNode *head)
	{
		if (head == NULL || head->next == NULL) {
			// return head;
			return ;
		}
		
		ListNode *cur = head;	
		std::vector<ListNode *> vct;
		while ( cur != NULL) {
			vct.push_back( cur);
		
			cur = cur->next;
		}

		ListNode *rvs = NULL;
		ListNode *newList0 = new ListNode(0);
		cur = head;
		ListNode *newcur = newList0;
		int cnt = 0;
		int size = vct.size();
		while ( cur != NULL && cnt <= size + 1) {
			rvs = vct.back();
			vct.pop_back();
			if (rvs == cur) {
				// cout << cur->val << endl;
				// cout << "pon" << endl;
				newcur -> next = cur;
				newcur = newcur -> next;
				newcur -> next = NULL;
				break;
			} else {
				// cout << cur->val << endl;
				// cout << rvs->val << endl;
				// cout << "pin" << endl;
				newcur ->next = cur;
				cur = cur -> next;
				newcur -> next ->next = rvs;
				newcur = newcur -> next ->next;
				newcur -> next = NULL;
			}
			cnt = cnt + 2;
		}
		delete newList0;
	}

	void test(void)
	{
		ListNode tn1(1), tn2(2), tn3(3), tn4(4),tn5(5);
		tn1.next = &tn2;
		tn2.next = &tn3;
		tn3.next = &tn4;
		tn4.next = &tn5;
		print(&tn1);
		reorderList(&tn1);
		print(&tn1);
	}
	void print(ListNode *cur)
	{
		while ( cur != NULL) {
			cout << cur->val << " ";
			cur = cur -> next;
		}
		cout << endl;
	}
};

int main()
{
	Solution ss;
	ss.test();
	cout << "hello world" << endl;
	return 0;
}