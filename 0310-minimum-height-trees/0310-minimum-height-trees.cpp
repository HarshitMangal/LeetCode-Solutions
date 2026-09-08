class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int>ans;
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        //leaf removal process
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        int remaining=n;
        while(remaining>2){
            int size=q.size();
            remaining-=size;
            while(size--){
               int node=q.front();
               q.pop();
               for(auto it:adj[node]){
                degree[it]--;
                if(degree[it]==1){
                    q.push(it);
                }
               }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};