class Solution {
public:
    int solve(string &s,vector<int>&dp,int idx){
        int n=s.length();
        if(idx>=n) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int ways=0;
       if(s[idx]=='0') return 0;
       ways=solve(s,dp,idx+1);

        // two length case
        if(idx+1<n){
            string temp=s.substr(idx,2);
            int num=stoi(temp);
            if(num>=10&&num<=26){
             ways+=   solve(s,dp,idx+2);
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
