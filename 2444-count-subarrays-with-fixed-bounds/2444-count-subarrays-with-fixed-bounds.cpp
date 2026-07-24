class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int minkindex=-1;
        int maxkindex=-1;
        int culpetindex=-1;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxK||nums[i]<minK){
              culpetindex=i;
            }
            if(nums[i]==minK){
                minkindex=i;
            }
            if(nums[i]==maxK){
                maxkindex=i;
            }
            int smaller=min(minkindex,maxkindex);
            long long temp=smaller-culpetindex;
            ans+=(temp<0?0:temp);
        }
        return ans;

    }

};