class Solution {
    int mod = 1e9+7;
    int solve(int day ,int delay ,int forget, vector<int>&dp){
        if(day == 1) {
            return 1;
        }
        if(dp[day] != -1){
             return dp[day] ;
        }
        int result = 0;
        for( int i = day-forget+1 ; i <= day -delay ; i++){
               if(i > 0){
                result = (result + solve(i , delay , forget , dp)) % mod;
               }
        }
        return dp[day] = result;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,-1);
        int total = 0;
        for( int day = n-forget+1 ; day <= n ; day++){
            if(day > 0){
                 total = (total + solve(day , delay , forget ,dp)) % mod;
            }
        }
        return total;
    }
};