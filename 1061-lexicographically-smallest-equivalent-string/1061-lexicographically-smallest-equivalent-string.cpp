class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& component)
    {
        vis[node] = 1;
        component.push_back(node);

        for (int nei : adj[node])
        {
            if (!vis[nei])
                dfs(nei, adj, vis, component);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        vector<vector<int>> adj(26);

        // Build graph
        for (int i = 0; i < s1.size(); i++)
        {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(26, 0);

        // rep[i] = smallest character in i's component
        vector<int> rep(26);

        for (int i = 0; i < 26; i++)
        {
            if (!vis[i])
            {
                vector<int> component;

                dfs(i, adj, vis, component);

                int mn = *min_element(component.begin(), component.end());

                for (int x : component)
                    rep[x] = mn;
            }
        }

        string ans = "";

        for (char c : baseStr)
        {
            ans += char(rep[c - 'a'] + 'a');
        }

        return ans;
    }
};