class Solution {
     private:
     bool check(int start,int n,vector<vector<int>>& graph, vector<int>color ){
        color[start]=-1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto & it: graph[node]){
               // color same  nahi raha to
               if(color[it]==-1){
                  color[it]=!color[node];
                  q.push(it);
               } 
               // color same raha 
               else if(color[it]==color[node]){
                       return false;
                   }
               }
        }
        return true;
     }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
       for(int i=0; i<n; i++){
             color[i]=-1;
             if(check(i,n,graph,color)==false){
                return false;
             }
       }
              return true;
    }
};