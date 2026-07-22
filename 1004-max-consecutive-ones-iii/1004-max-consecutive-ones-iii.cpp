class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        //brute force
        // int ans=0;
        // for(int i=0;i<n;i++){
        //    int count=0;
        //    for(int j=i;j<n;j++){
        //     if(nums[j]==0){
        //         count++;
        //     }
        //     if(count>k)  break;
        //     ans=max(ans,j-i+1);
        //    }
        // }
        // return ans;

        //optimize
        int ans=0;
        int i=0;
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                count++;
            }
            while(count>k){
                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};