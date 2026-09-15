class Solution {
public:
    int solve(string &s,vector<int>&dp,int idx){
        int n=s.length();
        if(idx>=n) return 1;
          if(dp[idx]!=-1) return dp[idx];
        int ways=0;
        //sabse phle one ke
        if(s[idx]=='0') return dp[idx]=0;
        ways=solve(s,dp,idx+1);
        if(idx+2<=n){
            int temp=stoi(s.substr(idx,2));
            if(temp>=1&&temp<=26){
            ways+=solve(s,dp,idx+2);
            }
        }
        return dp[idx]=ways;


    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solve(s,dp,0);

        
    }
};