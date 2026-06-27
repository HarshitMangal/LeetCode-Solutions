class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
            int n=nums.size();
         int low=0;
         int high=n-1;
         while(low<=high){
            int mid=low+(high-low)/2;
            if(mid+1<n&&nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else high=mid-1;
         }
         return low;
    }
};