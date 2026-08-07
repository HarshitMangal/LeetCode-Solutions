class Solution {
public:
   int solve(vector<int>&nums,int L,int M){
    int n=nums.size();
    //ab usme window ki help se nikalenge yar
    int maxleft=0;
    int ans=0;
    for(int mend=L+M-1;mend<n;mend++){
        int lend=mend-M;
        int lstart=lend-L;
        int mblocksum=nums[mend]-nums[lend];
        int lblocksum=nums[lend]-(lstart<0?0:nums[lstart]);
        maxleft=max(maxleft,lblocksum);
        ans=max(ans,maxleft+mblocksum);
    }
    return ans;

   }
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n=nums.size();
        //sabse phle hum prefix sum banaynge yar
          vector<int>prefix(n,0);
          prefix[0]=nums[0];
          for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
          }


        return max(solve(prefix,L,M),solve(prefix,M,L));

        
    }
};