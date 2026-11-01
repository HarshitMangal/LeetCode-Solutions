class Solution {
public:
    int minMoves(vector<int>& nums) {
        //topic array,math
        int mini=INT_MAX;
        for(int i:nums) mini=min(mini,i);
        
        int ans=0;
        for(int i:nums) ans+=i-mini;
        return ans;


        
    }
};