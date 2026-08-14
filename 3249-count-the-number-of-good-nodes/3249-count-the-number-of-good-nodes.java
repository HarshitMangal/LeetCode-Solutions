class Solution {
    int ans = 0;

    int dfs(int node, int parent, List<List<Integer>> adj) {

        int subtreeSize = 1;

        int firstSize = -1;
        boolean good = true;

        for (int child : adj.get(node)) {

            if (child == parent)
                continue;

            int childSize = dfs(child, node, adj);

            // First child ka subtree size
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

    public int countGoodNodes(int[][] edges) {

        int n = edges.length + 1;

        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Undirected tree
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        dfs(0, -1, adj);

        return ans;
    }
}