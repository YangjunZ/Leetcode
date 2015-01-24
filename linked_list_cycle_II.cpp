#include <iostream>

using namespace std;
// https://oj.leetcode.com/problems/linked-list-cycle-ii/
//detect cycle, if exist, return the cycle starting node, or return NULL 
//for cycle circumference is m, slow start at head, fast start at head next node. slow and fast meet at x+1 node with constrains (2x+2 - (x-1)) mod m = 0; x= m-1 + am > the length from head to first crossing node. 
//to get the first crossing node, cur start at head. slow start at x+1, then they meet at y+1, with constrain (x+1+y - (y+1)) mod m =0, that means x mod m =0, impossible. that (x+1+y+a -(y-1)) mod m = 0. then a = 1. thus slow should start at next node after x+1.

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