class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto &e: edges){
              dist[e[0]][e[1]]=e[2];
               dist[e[1]][e[0]]=e[2];
        }
        // floyd warshall algorithm
        for(int i=0; i<n; i++) dist[i][i]=0;
        for(int k=0; k<n; k++){
            for(int i=0;i<n; i++){
                for(int j=0; j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        int cntCity=n;
        int cityNo=-1;
        
         for(int i=0;i<n; i++){
             int cnt=0;
                for(int j=0; j<n;j++){
                  if(dist[i][j]<=distanceThreshold)  
                  cnt++;
                    
              }
              if(cnt<=cntCity){
                  cntCity=cnt;
                  cityNo=i;
              }
         }
         return cityNo;
    }
};