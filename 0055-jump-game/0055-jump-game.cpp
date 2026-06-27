class Solution {
public:
    bool solve(vector<int>&nums,int idx,vector<int>&dp){
        int n=nums.size();
        if(idx>=n-1) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=0;i<nums[idx];i++){
           if(solve(nums,idx+i+1,dp)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]==0&&n==1) return true;
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);

        




    }
};