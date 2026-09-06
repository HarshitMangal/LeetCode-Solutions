class Solution {
public:
    int ispal(string &s, int i, int j) {
        int count = 0;

        while (j < s.length() && i >= 0 && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            count += ispal(s, i, i);

            // Even length palindrome
            count += ispal(s, i, i + 1);
        }

        return count;
    }
};