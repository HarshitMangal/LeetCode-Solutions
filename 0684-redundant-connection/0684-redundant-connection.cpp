class Solution {
public:
   bool dfs(vector<vector<int>>&adj,int u,int target,vector<bool>&visited){
     if(u==target) return true;
     visited[u]=true;
    for(auto it:adj[u]){
        if(!visited[it]){
            if(dfs(adj,it,target,visited)) return true;
        }
    }
    return false;
   }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>ans;
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(!adj[u].empty()&&!adj[v].empty()){
                 vector<bool>visited(n+1,false);
               if(dfs(adj,u,v,visited)){
                ans.push_back(u);
                ans.push_back(v);
               }
            }
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        return ans;
    } 
};