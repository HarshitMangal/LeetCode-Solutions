class Solution {
public:
     int solve(int target,vector<int>&coins,int idx,vector<vector<int>>&dp){
        int n=coins.size();
        if(target==0) return 1;
        if(idx>=n) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        if(coins[idx]<=target){
            return dp[idx][target]=solve(target-coins[idx],coins,idx,dp)+solve(target,coins,idx+1,dp);
        }
        return dp[idx][target]=solve(target,coins,idx+1,dp);

     }
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
         vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
         return solve(amount,coins,0,dp);
    }
};