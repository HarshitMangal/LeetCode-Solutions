class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = INT_MAX;

        vector<int> bits(32, 0);

        int i = 0;
        int Or = 0;

        for (int j = 0; j < n; j++) {

            // Add nums[j]
            for (int b = 0; b < 32; b++) {

                if (nums[j] & (1 << b)) {
                    bits[b]++;
                    Or |= (1 << b);
                }
            }

            // Shrink window
            while (i <= j && Or >= k) {

                ans = min(ans, j - i + 1);

                // Remove nums[i]
                for (int b = 0; b < 32; b++) {

                    if (nums[i] & (1 << b)) {

                        bits[b]--;

                        if (bits[b] == 0) {
                            Or ^= (1 << b);
                        }
                    }
                }

                i++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};