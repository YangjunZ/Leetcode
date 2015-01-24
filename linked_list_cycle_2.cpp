#include <iostream>

using namespace std;
// https://oj.leetcode.com/problems/linked-list-cycle/
// Given a linked list, determine if it has a cycle in it.
// Follow up:
// Can you solve it without using extra space?

//traversal the list,  for visited nodes, reverse it, if there exist a cycle, the end node must be original head node 


 // Definition for singly-linked list.
struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head-> next == NULL)
            return false;
        ListNode * slow = head;
        ListNode * fast = head->next;
        while( fast != NULL && fast->next != NULL){
            if( fast == slow)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }

    void test(void){
    	ListNode tn1(1), tn2(2), tn3(3), tn4(4), tn5(5);
    	tn1.next = & tn2;
    	tn2.next = & tn3;
    	tn3.next = & tn4;
    	tn4.next = & tn5;

    	if(hasCycle(&tn1)){
    		cout << "has cycle"<<endl;
    	}else{
    		cout << "no cycle"<<endl;
    	}
    }
};

int main()
{
	Solution ss;
	ss.test();

	cout << "hello world"<<endl;
	return 0;
}