class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        //first step  using sort
        sort(nums.begin(),nums.end());
        vector<int>arr;
        arr.push_back(nums[0]);
        //duplicate hatynegebunique baneye
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                arr.push_back(nums[i]);
            }
        }
        //ab ranghe ke accoriding check karenge
        int m=arr.size();
        int ans=INT_MAX;
        int i=0;
        for(int j=0;j<m;j++){
            while(arr[j]-arr[i]>=n){
              i++;
            }
            int windowsize=j-i+1;
            ans=min(ans,n-windowsize);
        }
        return ans;

    }
};