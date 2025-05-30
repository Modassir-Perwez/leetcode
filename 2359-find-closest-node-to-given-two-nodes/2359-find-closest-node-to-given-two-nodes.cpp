class Solution {
    // ya bfs ya dfs likho jo marji hai wo likho
        void dfs(vector<int>& edges, int node, vector<int>& dis, vector<bool> &visited){
            visited[node]=true;
            int v=edges[node];
            if(v!=-1 && !visited[v]){
                visited[v]=true;
                dis[v]=1+dis[node];
                dfs(edges , v , dis , visited);
            }
        }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       //mujhe question samjh me aa gya hai mai dry run kar chuka hu
       // firstly take two vector and store the distance from node1 and node2
       int n=edges.size();
       vector<int>dis1(n,INT_MAX); 
       vector<int>dis2(n,INT_MAX);
       //ham visted mark kar denge taki dubara read na kare
       vector<bool>visited1(n,false);
       vector<bool>visited2(n,false);
       //starting distance from same is 0
       dis1[node1]=0;
       dis2[node2]=0;
       //dfs used kar lo ya bfs 
       dfs(edges,node1 , dis1 , visited1);
       dfs(edges,node2 , dis2 , visited2);
        // max ka min nikalna hai
        int minDis=-1;
        int minDisTillNow=INT_MAX;
        //loop chala denge 
        for(int i=0; i<n; i++){
            int maxD=max(dis1[i],dis2[i]);
            if(minDisTillNow > maxD){
                minDisTillNow=maxD;
                minDis=i;
            }
        }
        return minDis;
    }
};