class Solution {
public:
    int uniqueLetterString(string s) {

        int n = s.size();

        vector<int> prev(n), next(n);

        vector<int> last(26, -1);

        // Previous occurrence
        for(int i = 0; i < n; i++) {

            int ch = s[i] - 'A';

            prev[i] = last[ch];

            last[ch] = i;
        }

        fill(last.begin(), last.end(), n);

        // Next occurrence
        for(int i = n - 1; i >= 0; i--) {

            int ch = s[i] - 'A';

            next[i] = last[ch];

            last[ch] = i;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            ans += (i - prev[i]) * (next[i] - i);

        }

        return ans;
    }
};