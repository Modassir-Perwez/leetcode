class Solution {
    int mod=1e9+7;
public:
    int nthMagicalNumber(int n, int a, int b) {
        int lcm=(a*b)/__gcd(a,b);
        long long left=min(a,b),right=1ll*n*min(a,b);
        int ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(mid/a + mid/b - mid/lcm < n){
                left=mid+1;
            }
            else{
                 ans=mid%mod;
                 right=mid-1;
            }
        }
        return ans;
        
    }
};