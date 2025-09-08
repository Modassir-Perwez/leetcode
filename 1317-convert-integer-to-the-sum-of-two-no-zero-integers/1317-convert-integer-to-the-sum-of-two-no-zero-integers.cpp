class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
         for(int i = 1 ; i < n ; i++){
            //check karo 0 to nahi hai so pahle string me convert karo phir check karo 
            int b = n-i;
            if((to_string(i) + to_string(b)).find('0') == string::npos){
                return {i,b};
            }
         }
         return {};
    }
};