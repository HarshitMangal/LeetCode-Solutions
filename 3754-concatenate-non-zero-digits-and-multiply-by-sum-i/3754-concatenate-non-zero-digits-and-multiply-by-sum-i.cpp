class Solution {
public:
    long long sumAndMultiply(int n) {
        string ans = "";
        long long sum = 0;

        while (n != 0) {
            int digit = n % 10;
            if (digit != 0) {
                sum += digit;
                ans.push_back(digit + '0');
            }
            n /= 10;
        }

        reverse(ans.begin(), ans.end());

        if (ans.empty()) return 0;

        long long num = stoll(ans);

        return num * sum;
    }
};