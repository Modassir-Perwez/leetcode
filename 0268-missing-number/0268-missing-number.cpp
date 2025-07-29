class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
//int ans=0;
        int n=nums.size();
        

        for(int i=0; i<n; i++){
             

       sum=sum+nums[i];
        
       // int ans= (n+1)*(n)/2-sum;

         
        }
        
        return  (n+1)*(n)/2-sum ;
    }
};