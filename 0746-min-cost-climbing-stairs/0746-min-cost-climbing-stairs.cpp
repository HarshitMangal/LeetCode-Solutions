class Solution {
public:
    int solve(vector<int>&arr,int idx,vector<int>&dp){
        int n=arr.size();
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int cost1=arr[idx]+solve(arr,idx+1,dp);
        int cost2=arr[idx]+solve(arr,idx+2,dp);
        return dp[idx]=min(cost1,cost2);

    }
    int minCostClimbingStairs(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int cost1=solve(arr,0,dp1);
        int cost2=solve(arr,1,dp2);
        return min(cost1,cost2);

    }
};