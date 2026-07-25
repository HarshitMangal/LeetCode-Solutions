class Solution {
public:
    int numberOfSubstrings(string s, int k) {
          int n = s.size();

        int total = n * (n + 1) / 2;
        int bad = 0;

        unordered_map<char, int> mp;

        int left = 0;

        for (int right = 0; right < n; right++) {

            mp[s[right]]++;

            while (mp[s[right]] >= k) {
                mp[s[left]]--;
                left++;
            }

            bad += (right - left + 1);
        }

        return total - bad;
    }
};