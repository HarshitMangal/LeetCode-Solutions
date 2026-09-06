class Solution {
public:
    bool solve(vector<int>&nums,int d,int mid){
        int n=nums.size();
        int count=1;
        int sum=0;
        for(auto it:nums){
            if(sum+it<=mid){
                sum+=it;
            }
            else{
                sum=it;
                count++;
            }
        }
        return count<=d;

    }
    int shipWithinDays(vector<int>& nums, int d) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
              if(solve(nums,d,mid)){
                  ans=mid;
                  high=mid-1;
              }
              else low=mid+1;
        }
        return ans;

    }
};