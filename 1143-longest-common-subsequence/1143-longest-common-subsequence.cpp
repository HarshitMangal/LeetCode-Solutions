class Solution {
public:
   int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    // int n=s1.length();
    // int j=s2.length();
    if(i==0||j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
    }
    else{
        return dp[i][j]=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
    }
    return dp[i][j];

   }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,n,m,dp);
    }
};