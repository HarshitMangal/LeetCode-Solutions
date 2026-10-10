class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            mx = max(mx, d);
        }

        long long total = 0;
        for (int d : diff) {
            total += d;
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;
        long long need = 0;

        for (int d : diff) {
            if (d > level) {
                need += d - level;
            }
        }

        long long ans = 0;
        long long remaining = k - need;

        for (int d : diff) {
            int finalDiff = min(d, level);
            ans += 1LL * finalDiff * finalDiff;
        }

        // Remaining operations reduce some differences by one more.
        for (int d : diff) {
            if (remaining > 0 && d >= level && level > 0) {
                ans -= 2LL * level - 1;
                remaining--;
            }
        }

        return ans;
    }
};