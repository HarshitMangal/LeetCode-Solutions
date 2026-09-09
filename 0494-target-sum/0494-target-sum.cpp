class Solution {
public:
        int  solve(vector<int>&nums,vector<vector<int>>&dp,int idx,int target){
        int n=nums.size();
        if(idx>=n) {
        if(target==0) return 1;
        return 0;
        }

        if(dp[idx][target]!=-1) return dp[idx][target];
        int take=0;
        if(nums[idx]<=target){
            take=solve(nums,dp,idx+1,target-nums[idx]);
        }
        int nottake=solve(nums,dp,idx+1,target);
      return dp[idx][target]   =take+nottake;
         
     }
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if((total+diff)%2!=0) return 0;
        if(total+diff<0) return 0;
        int target=(total+diff)/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return  solve(nums,dp,0,target);

        

    }
};