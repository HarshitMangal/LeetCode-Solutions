class Solution {
public:
 int solve(vector<int>&nums,int k){
    int n=nums.size();
    if(k<0) return 0;
      int i=0;
        int count=0;
        int ans=0;
        for(int j=0;j<n;j++){
            if(nums[j]%2!=0){
                count++;
            }
            while(count>k&&i<n){
                if(nums[i]%2!=0){
                    count--;
                }
                i++;
            }
            ans+=(j-i+1);

        }
        return ans;
 }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        //brute force
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int count=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]%2!=0){
        //             count++;
        //         }
        //         if(count==k) ans++;
        //         else if(count>k) break;
        //     }

        // }
        // return ans;
        //optimal
      
        //exactly k elenmnet   atmost(k)-atmost(k-1);
        return  solve(nums,k)-solve(nums,k-1);
    }
};