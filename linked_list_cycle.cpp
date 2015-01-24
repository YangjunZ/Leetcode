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
    	if(head== NULL || head->next ==NULL)
    		return false;
    	if(head -> next == head)
    		return true;

        ListNode* newHead, *cur, *tmp;
    	newHead = head;
    	cur = head->next;
    	while(cur != NULL){
    		if(cur ==  head){
    			return true;
    		}else{
    			tmp = cur;
    			cur = cur->next;

    			tmp->next = newHead;
    			newHead = tmp;
    		}

    	}
    	return false;
    }

    void test(void){
    	ListNode tn1(1), tn2(2), tn3(3), tn4(4), tn5(5);
    	tn1.next = & tn2;
    	tn2.next = & tn3;
    	tn3.next = & tn4;
    	tn4.next = & tn4;

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