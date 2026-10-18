
class Solution {
public:
    vector<vector<int>> dp;
    const int mod = 1e9 + 7;

    int solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left_arr, right_arr;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left_arr.push_back(nums[i]);
            } else {
                right_arr.push_back(nums[i]);
            }
        }

        long long x = solve(left_arr);
        long long y = solve(right_arr);
        long long z = dp[n - 1][left_arr.size()];

        return (((x * y) % mod) * z) % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        dp.resize(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = ((long long)dp[i - 1][j - 1]
                              + dp[i - 1][j]) % mod;
                }
            }
        }

        return (solve(nums) - 1 + mod) % mod;
    }
};
