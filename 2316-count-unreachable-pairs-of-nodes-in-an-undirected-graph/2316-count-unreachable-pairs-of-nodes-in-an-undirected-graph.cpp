class Solution {
public:
   void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, long long &count) {
        visited[node] = true;
        count++;
        for (auto v : adj[node]) {
            if (!visited[v]) {
                dfs(adj, visited, v, count);
            }
        }
   }

   long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<long long> componentsize;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long count = 0;
                dfs(adj, visited, i, count);  // pass by reference
                componentsize.push_back(count);
            }
        }

        long long pairs = 1LL * n * (n - 1) / 2;

        for (auto c : componentsize) {
            pairs -= c * (c - 1) / 2;
        }

        return pairs;
   }
};
