class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int a=0;a<nums.size()-1;a++){
           for(int b=a+1;b<nums.size();b++){
            if(nums[a]+nums[b]==target)
            return {a,b};
           } 
        }
        return {};// no sol found.
      
    
    }
};