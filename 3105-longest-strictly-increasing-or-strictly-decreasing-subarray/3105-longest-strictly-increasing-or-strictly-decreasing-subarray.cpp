class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int decreasing=1;
        int increasing=1;
        int maxincreasing=1;
        int maxdecreasing=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                increasing++;
                maxincreasing=max(maxincreasing,increasing);
                decreasing=1;
            }
            else if(nums[i]<nums[i-1]){
                decreasing++;
                maxdecreasing=max(maxdecreasing,decreasing);
                increasing=1;

            }
            else{
                increasing=1;
                decreasing=1;
            }

        }
        return max(maxincreasing,maxdecreasing);
        
    }
};