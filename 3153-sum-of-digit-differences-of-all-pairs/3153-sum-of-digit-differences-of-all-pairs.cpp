class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {

        int n = nums.size();
        long long ans = 0;
        while (nums[0] > 0) {

            unordered_map<int, int> mp;

            // Current digit ki frequency count karo
            for (int &num : nums) {
                int digit = num % 10;
                mp[digit]++;
                num /= 10;
            }

            // Current digit position ka contribution
            for (auto it : mp) {
                ans += 1LL * it.second * (n - it.second);
            }
        }
        return ans / 2;
    }
};