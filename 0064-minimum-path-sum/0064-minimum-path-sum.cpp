class Solution {
    int usingMem(int i,int j, vector<vector<int>>& grid,vector<vector<int>>&dp){
        //base case
        if(i==0 && j== 0) return grid[0][0];
        if(i<0 || j<0) return 1e9;// taki min lena hai to already ignore kar de
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=grid[i][j]+usingMem(i-1,j,grid,dp);
        int left=grid[i][j]+usingMem(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         //initiallise row 
         // using rec
         vector<vector<int>>dp(n,vector<int>(m+1,-1));
         return usingMem(n-1,m-1,grid,dp);
    }
};