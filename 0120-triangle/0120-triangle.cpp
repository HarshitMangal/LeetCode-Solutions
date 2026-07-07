class Solution {
public:
   int solve(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            dp[n-1][i] = mat[n-1][i];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = mat[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
   }

    int minimumTotal(vector<vector<int>>& mat) {
        return solve(mat);
    }
};