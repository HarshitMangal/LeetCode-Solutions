class Solution {
public:
  int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
    int n=nums1.size();
    int m=nums2.size();
    //non empty subsequence
  if(i>=n||j>=m) return INT_MIN;
  if(dp[i][j]!=-1) return dp[i][j];
  int left1=     nums1[i]*nums2[j]+max(0,solve(nums1,nums2,i+1,j+1,dp));
  int left= solve(nums1,nums2,i+1,j,dp);
  int right=  solve(nums1,nums2,i,j+1,dp);
  int skip=solve(nums1,nums2,i+1,j+1,dp);
    return dp[i][j]= max({left1,left,right,skip});

  }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(nums1,nums2,0,0,dp);


    }
};