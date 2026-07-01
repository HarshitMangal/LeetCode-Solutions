class Solution {
public:
   unordered_map<string,string>email;
    unordered_set<string>visited;
    unordered_map<string,vector<string>>adj;

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
          vector<vector<string>>ans;
          int n=accounts.size();
          for(auto it:accounts){
            string name=it[0];
            for(int i=1;i<it.size();i++){
               string u=it[1];
               string v=it[i];
               email[v]=name;
               adj[u].push_back(v);
               adj[v].push_back(u);
            }
          }

          //ab dfs lagake dalnege yar

          for(auto it:adj){
            string u=it.first;
            if(!visited.count(u)){
             vector<string>v;
             solve(v,u);
             sort(v.begin(),v.end());
              v.insert(v.begin(),email[u]);
              ans.push_back(v);
            }
    }

    return ans;
    }
};