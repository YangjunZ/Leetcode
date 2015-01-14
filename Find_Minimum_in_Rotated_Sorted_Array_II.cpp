#include <iostream>
#include <vector>

using namespace std;
// https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// What if duplicates are allowed?

class Solution {
public:
    int findMin(vector<int> &num) {
    	int l,r,mid;
    	l = 0;
    	r = num.size() -1;
    	
    	while(l < r){
    		mid = (l+r)/2;
    		if( num[mid] > num[r]){
    			l = mid + 1;
    		}else if(num[mid] == num[r] && num[l] >= num[r]){
                l = l + 1;// in case, 3,0,1,2,2,2,2
            }else{
    			r = mid;//not r = mid -1, because num[mid] maybe equal min, 
    		}
    	}
    	return num[l];
   }
};