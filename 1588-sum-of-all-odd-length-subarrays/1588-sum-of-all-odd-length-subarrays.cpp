class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size();

        int ans = 0;

        for(int i = 0; i < n; i++) {

            long long total = 1LL * (i + 1) * (n - i);

            long long odd = (total + 1) / 2;

            ans += arr[i] * odd;
        }

        return ans;
    }
};