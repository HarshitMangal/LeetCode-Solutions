class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi1=1;
        int maxi2=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
          maxi1*=nums[i];
          maxi2*=nums[n-1-i];
          ans=max({ans,maxi1,maxi2});
          if(maxi1==0) maxi1=1;
          if(maxi2==0) maxi2=1;
        }
        return ans;
    }
};