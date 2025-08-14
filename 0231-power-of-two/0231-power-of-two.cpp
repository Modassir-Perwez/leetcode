class Solution {
public:
    bool isPowerOfTwo(int n) {
  //using bit manipulation
       return  n>0 &&(n & (n-1))==0;
        
    }
};