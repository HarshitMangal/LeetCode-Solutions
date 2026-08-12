class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                // Check whether every present character
                // occurs at least k times
                bool valid = true;

                for(int x = 0; x < 26; x++) {
                    if(freq[x] > 0 && freq[x] < k) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};