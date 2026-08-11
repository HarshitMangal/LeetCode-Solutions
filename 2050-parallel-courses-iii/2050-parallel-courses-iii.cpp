class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        //using graph banayenge yar
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto it:relations){
            int u=it[0]-1;
            int v=it[1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
          queue<int>q;
          for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
          }
          vector<int>finish(n,0);
          for(int i=0;i<n;i++){
            finish[i]=time[i];
          }
          while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto v:adj[node]){
                //isme v tab start hoga tab u complete hoga
                finish[v]=max(finish[v],finish[node]+time[v]);
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
          }
          return *max_element(finish.begin(),finish.end());

    }
};