class Solution {
public:
    void sortColors(vector<int>& nums) {
       
 /* int count0=0,count1=0,count2=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==0) count0++;
          else if(nums[i]==1) count1++;
else count2++;
       }
       for(int i=0;i<count0;i++)
           nums[i]=0;
       
       for(int i=count0;i<count0+count1;i++)
           nums[i]=1;
          for(int i=count0+count1;i<nums.size();i++)
         nums[i]=2;*/
         int l=0,m=0,h=nums.size()-1;
         while(m<=h){
             if(nums[m]==0){
                 swap(nums[l],nums[m]);
                 l++;
                 m++;

             }else if(nums[m]==1){
                 m++;

             }
             else{
                 swap(nums[m],nums[h]);
                 h--;

             }
         }
         
    }
};