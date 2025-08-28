class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        /// To handle subarrays starting at index 0
               mp[0]=1;
        int presum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
             presum+=nums[i];
             int remove=presum-goal;
             // how many times of remove
             cnt+=mp[remove];
             mp[presum]+=1;
        }
        return cnt;
    }
};