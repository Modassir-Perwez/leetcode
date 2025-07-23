class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //base case
        if(n==1 && m==1 && !grid[0][0]) return 1;
        if(grid[0][0] || grid[n-1][m-1]) return -1;
        queue<pair<int,pair<int,int>>>q;
        // dis ,({row,col})
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
         q.push({1,{0,0}});
         while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int drow=-1; drow<=1; drow++){
                for(int dcol=-1; dcol<=1; dcol++){
                    int nrow=row+drow;
                    int ncol=col+dcol;
                    if(ncol>=0 && ncol<m && nrow>=0 && nrow<n &&
                        grid[nrow][ncol]==0){
                            if(dis+1<dist[nrow][ncol]){
                                dist[nrow][ncol]=dis+1;
                                if(nrow==n-1 && ncol==n-1) return dis+1;
                                 q.push({dis + 1, {nrow, ncol}});
                            }
                        }
                }
            }
         }
         return -1;
    }
};