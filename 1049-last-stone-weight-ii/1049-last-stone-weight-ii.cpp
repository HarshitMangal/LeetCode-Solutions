class Solution {
public:

    int solve(int i, int cap, vector<int>& stones,
              vector<vector<int>>& dp) {

        if (i == stones.size())
            return 0;

        if (dp[i][cap] != -1)
            return dp[i][cap];

        int notTake = solve(i + 1, cap, stones, dp);

        int take = 0;

        if (stones[i] <= cap)
            take = stones[i] + solve(i + 1, cap - stones[i], stones, dp);

        return dp[i][cap] = max(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {

        int total = 0;

        for (int x : stones)
            total += x;

        int cap = total / 2;

        vector<vector<int>> dp(stones.size(),
                               vector<int>(cap + 1, -1));

        int subsetSum = solve(0, cap, stones, dp);

        return total - 2 * subsetSum;
    }
};