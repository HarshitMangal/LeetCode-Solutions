class Solution {
public:
  int solve(string &s,string&t,vector<vector<int>>&dp,int i,int j){
     int n=s.length();
     int m=t.length();
     //base case 
     if(j==0) return 1;
     if(i==0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i-1]==t[j-1]){
        return dp[i][j]=solve(s,t,dp,i-1,j-1)+solve(s,t,dp,i-1,j);
     }
     else return dp[i][j]=solve(s,t,dp,i-1,j);
  }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,dp,n,m);

        
    }
};