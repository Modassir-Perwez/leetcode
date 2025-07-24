class Solution {
public:
    int search(vector<int>& nums, int target) {
        // sorted array so we can used the Binary search which time complexity is O(logn)
        //dry run [-1,0,3,5,9,12]
        int n=nums.size();
        int left =0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                   return mid;
            }
            else if(nums[mid]>target){
               right=mid-1;
        }
        else{
                left=mid+1;
              }
        }
        return -1;
    }
};