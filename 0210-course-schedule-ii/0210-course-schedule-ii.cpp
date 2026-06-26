class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int>ans;
          vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
          int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
         if(count==n)
    return ans;

return {};
    }
};