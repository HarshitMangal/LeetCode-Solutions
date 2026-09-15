class Solution {
public:
    int solve(vector<int>&prices,vector<vector<vector<int>>>&dp,int i,int canbuy,int k){
        int n=prices.size();
        if(i>=prices.size()||k==0) return 0;
        if(dp[i][k][canbuy]!=-1) return dp[i][k][canbuy];
        if(canbuy==1){
            int buy=-prices[i]+solve(prices,dp,i+1,0,k);
            int skip=solve(prices,dp,i+1,1,k);
            return dp[i][k][canbuy]=max(buy,skip);
        }
        else{
            int sell=prices[i]+solve(prices,dp,i+1,1,k-1);
            int skip=solve(prices,dp,i+1,0,k);
            return dp[i][k][canbuy]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         int k=2;
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
         return solve(prices,dp,0,1,k);



        
    }
};