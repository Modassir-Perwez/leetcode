class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int n=nums.size();
       int left=0;
       long long currSum=0;
       long long maxSum=0;
       unordered_set<int>st;
       for(int right=0; right<n; right++ ){
        // while loop chalo aggar duplicate element hua to chalege warna false ho jayega
        while(st.count(nums[right])){
            currSum -=nums[left];
            st.erase(nums[left]);
            left++;
        }
           currSum +=nums[right];
           st.insert(nums[right]);
           maxSum=max(maxSum,currSum);
       }
       return maxSum;
    }
};