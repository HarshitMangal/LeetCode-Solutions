class Solution {
public:
  int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    int n=s1.length();
    int m=s2.length();
    if(i==n) return s2.length()-j;
    if(j==m) return s1.length()-i;    //s1 = "ab s2 = "abc"
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
    int delet=1+solve(s1,s2,i+1,j,dp);
    int insert=1+solve(s1,s2,i,j+1,dp);
    int rep=1+solve(s1,s2,i+1,j+1,dp);
    return dp[i][j]=min({insert,delet,rep});

  }
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);


    }
};