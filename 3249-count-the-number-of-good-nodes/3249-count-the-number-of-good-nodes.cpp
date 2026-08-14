class Solution {
public:
    int ans = 0;

    int dfs(int node, int parent, vector<vector<int>>& adj) {
        int subtreeSize = 1;

        int firstSize = -1;
        bool good = true;

        for (int child : adj[node]) {
            if (child == parent) continue;

            int childSize = dfs(child, node, adj);

            // Pehle child ka size store karo
            if (firstSize == -1) {
                firstSize = childSize;
            }
            // Baaki children ka size same hona chahiye
            else if (firstSize != childSize) {
                good = false;
            }

            subtreeSize += childSize;
        }

        if (good) {
            ans++;
        }

        return subtreeSize;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj);

        return ans;
    }
};