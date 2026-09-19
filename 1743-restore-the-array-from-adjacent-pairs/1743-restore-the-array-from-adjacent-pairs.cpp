class Solution {
public:
      void dfs(int node,
             unordered_map<int, vector<int>>& adj,
             unordered_set<int>& visited,
             vector<int>& ans) {

        visited.insert(node);
        ans.push_back(node);

        for (int next : adj[node]) {
            if (!visited.count(next)) {
                dfs(next, adj, visited, ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
         
      unordered_map<int, vector<int>> adj;

        for (auto &p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        int start;
        for(auto it:adj){
            if(it.second.size()==1){
                start=it.first;
                break;
            }
        }


          vector<int> ans;
        unordered_set<int> visited;

        dfs(start, adj, visited, ans);

        return ans;

    }
};