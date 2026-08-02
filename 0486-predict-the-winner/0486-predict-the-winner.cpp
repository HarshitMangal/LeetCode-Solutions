class Solution {
public:
    int solve(vector<int>& arr, vector<vector<int>>& dp, int i, int j) {
      if (i > j) return 0;  // base case: invalid subarray
      if (dp[i][j] != -1) return dp[i][j];
      
      int pickLeft = arr[i] + min(
          solve(arr, dp, i + 2, j),
          solve(arr, dp, i + 1, j - 1)
      );
      
      int pickRight = arr[j] + min(
          solve(arr, dp, i + 1, j - 1),
          solve(arr, dp, i, j - 2)
      );
      
      return dp[i][j] = max(pickLeft, pickRight);
   }
    bool predictTheWinner(vector<int>& piles) {
             int n=piles.size();
         int sum=accumulate(piles.begin(),piles.end(),0);
         vector<vector<int>> dp(n, vector<int>(n, -1));
        int player1_score=solve(piles,dp,0,n-1);
        int player2_score=sum-player1_score;
        return player1_score>=player2_score;
        
    }
};