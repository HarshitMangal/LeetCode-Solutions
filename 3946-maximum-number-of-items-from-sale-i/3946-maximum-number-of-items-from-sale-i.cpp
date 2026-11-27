class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
      int n=items.size();
        vector<int>bonus(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0){
                    bonus[i]++;
                }
            }
            
        }
        int minprice=INT_MAX;
        for(auto &it:items){
            minprice=min(minprice,it[1]);
        }
            vector<int>dp(budget+1,-1e9);
           dp[0]=0;
           for(int i=0;i<n;i++){
               int cost=items[i][1];
               int gain=1+bonus[i];
               for(int b=budget;b>=cost;b--){
                   dp[b]=max(dp[b],dp[b-cost]+gain);
               }
           }
       int ans=0;
     for(int spent=0;spent<=budget;spent++){
         if(dp[spent]<0) continue;
         int remaining=budget-spent;

         ans=max(ans,dp[spent]+remaining/minprice);
     }
return ans;
        
        
    }
};