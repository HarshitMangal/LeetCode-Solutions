class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;

        int start = 0;

        for (int end = 0; end < n; end++) {

            if (end - start + 1 >= k) {

                bool found = false;

                for (int l = start; l <= end - k + 1; l++) {
                    if (isPalindrome(s, l, end)) {
                        ans++;
                        start = end + 1;
                        found = true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};