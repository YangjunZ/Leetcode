class Solution {
public:
    int singleNumber(int A[], int n) {
  		// int res=0;
  		for(int i=1; i<n; ++i){
  			A[i] ^=  A[i-1];
  		}      
  		return A[n-1];
    }
};