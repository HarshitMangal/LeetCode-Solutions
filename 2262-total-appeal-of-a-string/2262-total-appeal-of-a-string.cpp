class Solution {
public:
    long long appealSum(string s) {
      int n = s.size();

        vector<int> last(26, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int ch = s[i] - 'a';

            ans += 1LL * (i - last[ch]) * (n - i);

            last[ch] = i;
        }
        return ans;

    }
};