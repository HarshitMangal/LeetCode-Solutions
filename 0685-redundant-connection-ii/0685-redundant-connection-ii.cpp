class Solution {
public:

    // DSU
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void union_set(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    vector<int> findRedundantDirectedConnection(
        vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        // v -> edge index
        vector<int> indegree(n + 1, -1);

        int first = -1;
        int second = -1;

        // Find node having 2 parents
        for (int i = 0; i < n; i++) {

            int v = edges[i][1];

            if (indegree[v] == -1) {
                indegree[v] = i;
            }
            else {
                first = indegree[v];
                second = i;
                break;
            }
        }

        // Skip second edge temporarily
        for (int i = 0; i < n; i++) {

            if (i == second)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];

            int pu = find(u);
            int pv = find(v);

            // Cycle
            if (pu == pv) {

                // 2 parents + cycle
                if (first != -1) {
                    return edges[first];
                }

                // Only cycle
                return edges[i];
            }

            union_set(u, v);
        }

        // 2 parents but no cycle
        return edges[second];
    }
};