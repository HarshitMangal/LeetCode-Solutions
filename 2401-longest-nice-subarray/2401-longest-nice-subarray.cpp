class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int mask=0;
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++){
            while((mask&nums[j])!=0){
                mask=mask^nums[i];
                i++;
            }
            mask|=nums[j];
            ans=max(ans,j-i+1);

        }
        return ans;
    }
        
};