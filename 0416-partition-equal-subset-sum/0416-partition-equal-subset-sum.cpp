class Solution {
public:
        int solve(vector<int>&arr,int target,vector<vector<int>>&dp,int idx){
         int n=arr.size();
         if(target==0) return 1;
         if(idx<0) return 0;
         if(dp[idx][target]!=-1) return dp[idx][target];
         int take=0;
         if(arr[idx]<=target){
              take=solve(arr,target-arr[idx],dp,idx-1);
         }
         int nottake=solve(arr,target,dp,idx-1);
         return dp[idx][target]=take||nottake;
     }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0) return false;
        int target=sum/2;
         vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(arr,target,dp,n-1);
    }
};