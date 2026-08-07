class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<int>ans;
        //using dfs se karenge yar
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        vector<bool>suspecious(n,false);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        //ab hum suspiciou vector vanayenge yar
        queue<int>q;
        q.push(k);
        suspecious[k]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                indegree[it]--;
                if(!suspecious[it]){
                    q.push(it);
                    suspecious[it]=true;
                }
            }
        }
        bool cannotremove=false;
        for(int i=0;i<n;i++){
            if(suspecious[i]==true&&indegree[i]>0){
              cannotremove=true;
              break;
            }
            if(!suspecious[i]){
                ans.push_back(i);
            }


        }
        if(cannotremove==true){
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return ans;



    }
};