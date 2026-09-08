class Solution {
public:
    bool dfs( vector<vector<int>>&adj,int u,int v,vector<bool>&visited){
        if(u==v) return true;
        visited[u]=true;
        for(auto it:adj[u]){
            if(!visited[it]){
                if(dfs(adj,it,v,visited)) return true;
            }
        }
        return false;

    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        // int n=pre.size();
       vector<vector<int>>adj(n);
       for(auto it:pre){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
       }
        vector<bool>ans;
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            vector<bool>visited(n,false);
           ans.push_back(dfs(adj,u,v,visited));

        }
        return ans;

        
    }
};