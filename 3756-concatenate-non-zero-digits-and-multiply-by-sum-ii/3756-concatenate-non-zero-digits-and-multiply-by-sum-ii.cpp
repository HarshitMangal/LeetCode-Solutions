class Solution {
public:
  const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // prefix sum of digits (for the "sum" part)
        vector<long long> pref(n +1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (s[i] - '0');

        // B[i] = zero-skipped number formed by s[0..i-1], mod MOD
        // cntNZ[i] = count of non-zero digits in s[0..i-1]
        vector<long long> B(n + 1, 0);
        vector<int> cntNZ(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if (d != 0) {
                B[i + 1] = (B[i] * 10 + d) % MOD;
                cntNZ[i + 1] = cntNZ[i] + 1;
            } else {
                B[i + 1] = B[i];          // multiply by 1, add 0
                cntNZ[i + 1] = cntNZ[i];
            }
        }

        // precompute powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = pref[r + 1] - pref[l];

            int k = cntNZ[r + 1] - cntNZ[l];   // non-zero digits in [l, r]
            long long x = ((B[r + 1] - B[l] * pow10[k]) % MOD + MOD) % MOD;

            ans.push_back((int)((x * sum) % MOD));
        }
        return ans;
    }
};