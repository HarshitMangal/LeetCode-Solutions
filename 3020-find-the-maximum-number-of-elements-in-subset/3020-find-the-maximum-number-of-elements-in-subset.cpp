class Solution {
public:
  const long long LIMIT = 1000000000;
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &it : freq) {

            long long x = it.first;

            if (x == 1)
                continue;

            int len = 0;

            while (freq.count(x) && freq[x] >= 2) {

                len += 2;

                if (x > sqrt(LIMIT))
                    break;

                x = x * x;
            }

            if (freq.count(x) && freq[x] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};