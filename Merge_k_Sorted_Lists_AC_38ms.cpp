#include <iostream>
#include <vector>
#include <cstdarg>
using namespace std;

// Merge k Sorted Lists


struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( NULL ) {}
};

class Solution
{
public:
	ListNode *merge( ListNode *l1, ListNode *l2 )
	{
		ListNode *head = new ListNode( -1 );
		ListNode *cur = head;
		while ( l1 && l2 ) {
			if ( l1->val < l2->val ) {
				cur ->next = l1;
				cur = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
		}
		if ( l1 ) {
			cur->next = l1;
		}
		if ( l2 ) {
			cur->next = l2;
		}
		cur = head->next;
		delete head;
		return cur;
	}

	ListNode *mergeKLists( vector<ListNode *> &lists )
	{
		if ( lists.size() == 0 ) return NULL;
		if ( lists.size() == 1 ) return lists[0];
		int cnt = lists.size();
		vector<ListNode *> vs, vd;
		vs = lists;
		while ( vs.size() > 1 ) {
			int i = 0;
			vd.clear();
			while ( i + 1 < vs.size() ) {
				vd.push_back( merge( vs[i++], vs[i++] ) );
			}
			if ( i < vs.size() )
				vd.push_back( vs[i] );
			vs = vd;
		}
		return vs[0];
	}
	void print( vector<ListNode *> &lists )
	{
		ListNode *ln = mergeKLists( lists );
		ListNode *cur = ln;
		while ( cur ) {
			cout << cur->val << ",";
			cur = cur->next;
		}
		cout << endl;
	}
};

ListNode *generateList( int first, ... )
{
	ListNode  head( -1 );
	ListNode *cur = &head;
	va_list vl;
	va_start( vl, first );
	int tmp = va_arg( vl, int );
	while ( tmp != -11 ) {
		// cout << tmp<<",";
		ListNode *tmpN = new ListNode( tmp );
		cur ->next = tmpN;
		cur = tmpN;
		tmp = va_arg( vl, int );
	}
	va_end( vl );
	return head.next;
}

int main( int argc, char const *argv[] )
{
	/* code */
	ListNode *ln1 =  generateList( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -11 );
	ListNode *ln2 =  generateList( 0, -33, -22, -20, -19, -18, -11 );
	ListNode *ln3 =  generateList( 0, 10, 11, 12, 23, 34, 54, 546, 2122, -11 );
	ListNode *ln4 =  generateList( 0, 2, 4, 6, 8, 10, 12, 14, 16, -11 );
	// ListNode *ln5 =  generateList( 0, -5, -4, -3, -2, -1, 0, 4, 6, 7, -11 );
	ListNode *ln5 =  generateList( 0, -11 );
	vector<ListNode *> vv;
	vv.push_back( ln1 );
	vv.push_back( ln2 );
	vv.push_back( ln3 );
	vv.push_back( ln4 );
	vv.push_back( ln5 );
	Solution ss;
	ss.print(vv);
	return 0;
}