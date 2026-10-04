class Solution {
public:
     unordered_map<string,string>mp;
           unordered_set<string>visited;
           unordered_map<string ,vector<string >>adj;
    void solve(vector<string>&v,string u){
        visited.insert(u);
        v.push_back(u);
        for(auto it:adj[u]){
            if(!visited.count(it)){
                solve(v,it);
            }
        }

    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
           int n=accounts.size();
           for(int i=0;i<n;i++){
            string name=accounts[i][0];
            for(int j=1;j<accounts[i].size();j++){
                string u=accounts[i][1];
                string v=accounts[i][j];
                mp[u]=name;
                if(u!=v){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }

            }
           }
            vector<vector<string>>ans;
           for(int i=0;i<n;i++){
            string u=accounts[i][1];
            vector<string>v;
            if(!visited.count(u)){
            solve(v,u);
            
            sort(v.begin(),v.end());
            v.insert(v.begin(),mp[u]);
            ans.push_back(v);
           }
           }
           return ans;
  
    }
};