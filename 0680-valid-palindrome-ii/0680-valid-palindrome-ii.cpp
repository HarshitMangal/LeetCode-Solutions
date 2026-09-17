class Solution {
public:
    bool ispal(string &s, int i, int j) {
        int n = s.length();

        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        if(ispal(s, i, j)) return true;

        while(i <= j) {

            if(s[i] != s[j]) {

                if(ispal(s, i + 1, j))
                    return true;

                if(ispal(s, i, j - 1))
                    return true;

                return false;   // dono fail → false
            }

            i++;
            j--;
        }

        return false;
    }
};