class Solution {
public:
   int ans=INT_MAX;
   void dfs(vector<vector<pair<int,int>>>&adj,int u,vector<bool>&visited){
      visited[u] =true;
      for(auto p:adj[u]){
        int v=p.first;
        int w=p.second;
        ans=min(ans,w);
        if(!visited[v]) dfs(adj,v,visited);
      }

   }
    int minScore(int n, vector<vector<int>>& graph) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:graph){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool>visited(n+1,false);
        dfs(adj,1,visited);
        return ans;
    }
};