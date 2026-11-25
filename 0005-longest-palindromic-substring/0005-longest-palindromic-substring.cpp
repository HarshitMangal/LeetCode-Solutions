class Solution {
public:
    // Use -1 = unvisited, 0 = false, 1 = true
    bool pal(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return true;           // base case
        if (dp[i][j] != -1) return dp[i][j]; // ✅ correct memo check

        if (s[i] != s[j]) return dp[i][j] = 0;

        return dp[i][j] = pal(s, i + 1, j - 1, dp); // ✅ recursive, indices stay correct
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 0, start = 0;

        // -1 = unvisited
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (pal(s, i, j, dp)) {
                    int len = j - i + 1;
                    if (len > maxlen) {
                        maxlen = len;
                        start = i;        // ✅ store start index, not substr yet
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};