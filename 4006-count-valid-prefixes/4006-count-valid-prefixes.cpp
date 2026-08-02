class Solution {
public:
    int countValidPrefixes(string s) {
             int cnt0 = 0, cnt1 = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '0')
                cnt0++;
            else
                cnt1++;

            if (abs(cnt0 - cnt1) <= 1)
                ans++;
        }

        return ans;


    }
};