class Solution {
public:

    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> quiet;

    void dfs(int i) {

        // agar already calculate ho chuka hai
        if(ans[i] != -1)
            return;

        // initially khud ko answer maan lo
        ans[i] = i;

        // i se richer log
        for(auto x : graph[i]) {

            dfs(x);

            // x ka best answer mil chuka hai
            if(quiet[ans[x]] < quiet[ans[i]]) {
                ans[i] = ans[x];
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer,
                            vector<int>& quiet) {

        int n = quiet.size();

        this->quiet = quiet;

        graph.resize(n);
        ans.assign(n, -1);

        for(auto it : richer) {

            int a = it[0];
            int b = it[1];

            // a is richer than b
            graph[b].push_back(a);
        }

        for(int i = 0; i < n; i++) {
            dfs(i);
        }

        return ans;
    }
};