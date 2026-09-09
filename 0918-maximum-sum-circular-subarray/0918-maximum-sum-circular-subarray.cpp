class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
         int sum1=0;
         int sum2=0;
         int sum=0;
         bool neg=true;
        for(int i=0;i<n;i++){
            if(nums[i]>0) neg=false;
            sum1+=nums[i];
            sum2+=nums[i];
            sum+=nums[i];
            maxsum=max(maxsum,sum1);
            minsum=min(minsum,sum2);
            if(sum1<0) sum1=0;
            if(sum2>0) sum2=0;
        }
        if(neg==true) return *max_element(nums.begin(),nums.end());
        return max(maxsum,sum-minsum);
    }
};