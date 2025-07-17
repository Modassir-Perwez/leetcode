class Solution {
    private:
    bool dfs(vector<vector<int>>&graph,int node,vector<int>&vis){
        if(vis[node]>0){
            //return true if already vis
            return vis[node]==2;
        }
        //mark vis
        vis[node]=1;
          for(int next: graph[node]){
            if(vis[next]==1 || !dfs(graph,next,vis)){
                return false;
            }
          }
        
            vis[node]=2;
            return true;
         
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        //logic kya hai socho
        //first of all it is graph question and undertand what the question say what i can do for brute force 
        // cfreate vis 
        vector<int>vis(n,0);
          for(int i=0;i<n;i++){
            if(dfs(graph,i,vis)){
                ans.push_back(i);
            }
          }
        return ans;
    }
};