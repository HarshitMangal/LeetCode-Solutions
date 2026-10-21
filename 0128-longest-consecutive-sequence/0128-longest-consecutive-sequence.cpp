class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mx=INT_MIN;
        int count=1;
        if(n==0) return 0;
        for(int i=1;i<n;i++){
        
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                 count++;
            }
            else {
                mx=max(mx,count);
                count=1;
            }
        

        }
        mx=max(mx,count);
        return mx;
    }
};