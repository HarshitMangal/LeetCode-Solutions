class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
            int n = nums.size();
        int ans = 0;

        // Har starting point
        for (int i = 0; i < n; i++) {

            int g = 0;

            // Har ending point
            for (int j = i; j < n; j++) {

                g = __gcd(g, nums[j]);

                if (g == k)
                    ans++;
            }
        }

        return ans;

    }
};