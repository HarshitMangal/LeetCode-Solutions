class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> prefix(n, 1e9);
        vector<int> suffix(n, 1e9);

        // prefix
        int left = 0;
        int sum = 0;
        int best = 1e9;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;
                best = min(best, len);
            }

            prefix[right] = best;
        }

        // suffix
        left = n - 1;
        sum = 0;
        best = 1e9;

        for (int right = n - 1; right >= 0; right--) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left--;
            }

            if (sum == target) {
                int len = left - right + 1;
                best = min(best, len);
            }

            suffix[right] = best;
        }

        int ans = 1e9;

        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] != 1e9 && suffix[i + 1] != 1e9) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};