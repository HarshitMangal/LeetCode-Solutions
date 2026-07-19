class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& costs, int idx,
              int aCount, int bCount) {

        int n = costs.size() / 2;

        // Invalid state
        if (aCount > n || bCount > n)
            return 1e9;

        // Base case
        if (idx == costs.size()) {
            if (aCount == n && bCount == n)
                return 0;
            return 1e9;
        }

        if (dp[idx][aCount][bCount] != -1)
            return dp[idx][aCount][bCount];

        int sendA = costs[idx][0] +
                    solve(costs, idx + 1,
                          aCount + 1,
                          bCount);

        int sendB = costs[idx][1] +
                    solve(costs, idx + 1,
                          aCount,
                          bCount + 1);

        return dp[idx][aCount][bCount] = min(sendA, sendB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {

        int n = costs.size() / 2;

        dp.assign(2 * n + 1,
                  vector<vector<int>>(n + 1,
                  vector<int>(n + 1, -1)));

        return solve(costs, 0, 0, 0);
    }
};