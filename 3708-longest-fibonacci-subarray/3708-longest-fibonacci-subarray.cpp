class Solution {
public:
    int longestSubarray(vector<int>& nums) {
           int n = nums.size();
        if(n < 2) return n;

        int ans = 2;

        for(int i = 2; i < n; i++) {
            if(nums[i] == nums[i-1] + nums[i-2]) {
                // extend sequence
                int len = 3;
                int j = i + 1;

                while(j < n && nums[j] == nums[j-1] + nums[j-2]) {
                    len++;
                    j++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};