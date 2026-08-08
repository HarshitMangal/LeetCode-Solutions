class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int src, int desc,
             vector<bool>& visited) {

        visited[src] = true;

        if (src == desc)
            return true;

        for (auto it : adj[src]) {

            if (!visited[it]) {

                if (dfs(adj, it, desc, visited))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int src, int desc) {

        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        return dfs(adj, src, desc, visited);
    }
};