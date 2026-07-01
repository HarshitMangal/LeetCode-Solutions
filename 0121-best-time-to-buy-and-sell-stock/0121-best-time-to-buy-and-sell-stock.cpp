class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=INT_MIN;
        int start=prices[0];
        for(int i=0;i<n;i++){
             maxi=max(maxi,prices[i]-start);
             start=min(start,prices[i]);
        }
        return maxi;
    }
};