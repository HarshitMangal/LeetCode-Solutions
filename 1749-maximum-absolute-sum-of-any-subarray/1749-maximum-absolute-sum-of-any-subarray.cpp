class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int sum = 0;
        int maxi = INT_MIN;

        // Maximum subarray sum
        for (int x : nums) {
            sum += x;
            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0;
        }

        sum = 0;
        int mini = INT_MAX;

        // Minimum subarray sum
        for (int x : nums) {
            sum += x;
            mini = min(mini, sum);

            if (sum > 0)
                sum = 0;
        }

        return max(maxi, abs(mini));
    }
};