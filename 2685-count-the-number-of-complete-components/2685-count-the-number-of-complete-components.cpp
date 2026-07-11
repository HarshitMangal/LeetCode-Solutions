class Solution {
public:
  int ec=0;
  int vc=0;
    void dfs(vector<bool>&visited,int u,vector<vector<int>>&adj){
        visited[u]=true;
        vc++;
        for(auto v:adj[u]){
            ec++;
            if(!visited[v]){
                dfs(visited,v,adj);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n+1,false);
        int count=0;
        for(int i=0;i<n;i++){
            ec=0;
            vc=0;
            if(!visited[i]){
                dfs(visited,i,adj);
                ec/=2;
                if(ec==((vc)*(vc-1))/2)
                 count++;
            }

        }
        return count;
        
    }
};