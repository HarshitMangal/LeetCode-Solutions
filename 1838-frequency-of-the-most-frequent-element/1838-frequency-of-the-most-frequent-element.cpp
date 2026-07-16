class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         int n=nums.size();
         sort(nums.begin(),nums.end());
         int i=0;
         int ans=1;
         long long  currsum=0;
         for(int j=0;j<n;j++){
             currsum+=nums[j];
             while((1LL*nums[j]*(j-i+1)-currsum)>k){
                currsum-=nums[i];
                i++;
             }
          ans=max(ans,j-i+1);

         }
         return ans;
    }
};