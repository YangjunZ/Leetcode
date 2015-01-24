#include <iostream>

using namespace std;
// https://oj.leetcode.com/problems/linked-list-cycle-ii/
//detect cycle, if exist, return the cycle starting node, or return NULL 

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if( head == NULL || head -> next == NULL)
    		return NULL;
    	ListNode * slow, *fast, *cross;
    	slow = head;
    	fast= head -> next;
    	while( fast != NULL && fast->next != NULL){
    		if( fast == slow)
    			break;
    		slow = slow -> next;
    		fast = fast -> next -> next;
    	}
    	if( fast != NULL &&  slow == fast){
    		cross = head;
    		slow = slow -> next;
    		while( cross != NULL){
    			if( cross == slow)
    				return cross;
    			cross = cross -> next;
    			slow = slow -> next;
    		}
    	}
    	return NULL;    
    }


    void test(void){
    	ListNode tn1(1), tn2(2), tn3(3), tn4(4), tn5(5), tn6(6);
    	tn1.next = & tn2;
    	tn2.next = & tn3;
    	tn3.next = & tn4;
    	tn4.next = & tn5;
    	tn5.next = & tn6;
		tn6.next = & tn3;
		ListNode * res = detectCycle( & tn1);
    	if( res != NULL){
    		cout << "has cycle:"<<res->val<<endl;
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