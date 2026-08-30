class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minidx, maxidx);
        int right = max(minidx, maxidx);

        int option1 = right + 1;          // Delete from left
        int option2 = n - left;          // Delete from right
        int option3 = left + 1 + n - right; // Left + Right

        return min({option1, option2, option3});
    }
};