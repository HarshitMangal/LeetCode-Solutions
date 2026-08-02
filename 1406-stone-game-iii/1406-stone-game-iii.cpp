class Solution {
public:
    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {

        int n = stoneValue.size();

        if (i >= n)
            return 0;

        if (dp[i] !=-1)
            return dp[i];

        int take1 = stoneValue[i] - solve(stoneValue, i + 1, dp);

        if (i + 1 < n)
            take1 =max(take1, stoneValue[i] + stoneValue[i + 1] - solve(stoneValue, i + 2, dp));

        if (i + 2 < n)
            take1 = max(take1,stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(stoneValue, i + 3, dp));

        return dp[i] = take1;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n+1, -1);

        int diff = solve(stoneValue, 0, dp);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";

        return "Tie";
    }
};