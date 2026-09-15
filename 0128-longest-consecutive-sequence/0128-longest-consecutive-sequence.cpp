class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int maxi=0;
        int count=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]+1==nums[i+1]){
                count++;
            }
            else if(nums[i]==nums[i+1]) continue;
            else{
                maxi=max(maxi,count);
                count=1;
            }
        }
        maxi=max(maxi,count);
        return maxi;
        
        
    }
};