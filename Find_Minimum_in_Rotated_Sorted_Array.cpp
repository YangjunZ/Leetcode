#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
    	int min = 0x7fffffff;
    	for(int i=0; i<num.size(); i++){
    		if(num[i] < min){
    			min = num[i];
    		}
    	}    
    	return min;
    }


};