class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
       //logic:- ya sara odd hoga ya to sara even hoga ya to odd even alternate hoga
       int even=0;
       int odd=0;
       for(int i=0; i<n;i++){
            if(nums[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
       } 
       int parity=nums[0]%2;
       int alternate=1;
       for(int i=1; i<n;i++){
        int currparity=nums[i]%2;
        if(currparity != parity){
        alternate++;
        parity=currparity;
        }
       }
       return max({odd,even,alternate});
    }
};