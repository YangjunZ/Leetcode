#include <iostream>
#include <vector>

using namespace std;

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
    		}else{
    			r = mid;//not r = mid -1, because num[mid] maybe equal min, 
    		}
    	}
    	return num[l];
   }
};