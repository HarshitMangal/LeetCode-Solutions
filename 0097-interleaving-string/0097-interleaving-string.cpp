class Solution {
public:
    
     bool solve(vector<vector<int>>&dp,string s1,string s2,int i,int j,int k,string s3){
        if(i==s1.length()&&j==s2.length()&&k==s3.length()) return true;
        if(k>=s3.length()) return false;
         if(dp[i][j]!=-1) return dp[i][j];
         bool result = false;

        if(i < s1.length() && s1[i] == s3[k]) {
            result = solve(dp,s1,s2,i+1,j,k+1,s3);
        }

        if(result == true) return dp[i][j] = true;

        if(j < s2.length() && s2[j] == s3[k]) {
            result = solve(dp,s1,s2,i,j+1,k+1,s3);
        }

        return dp[i][j] = result;
     }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int N=s3.length();
        if(n+m!=N) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return  solve(dp,s1,s2,0,0,0,s3);
    }
};