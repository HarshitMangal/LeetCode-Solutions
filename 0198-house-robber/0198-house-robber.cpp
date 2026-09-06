class Solution {
public:
   int solve(vector<int>&nums,vector<int>&dp,int idx){
       int n=nums.size();
       if(idx>=n) return 0;
       if(dp[idx]!=-1) return dp[idx];
       int take1=nums[idx]+solve(nums,dp,idx+2);
       int take2=solve(nums,dp,idx+1);
       return dp[idx]=max(take1,take2);
   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,dp,0);
    }
};