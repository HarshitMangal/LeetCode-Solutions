class Solution {
public:
    const int mod = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long res = k;
        long long op = 0;
        
        for (auto x : nums) {
            if (res < x) {
                long long need = (x - res);
                long long ops = (need + k - 1) / k;  // ceil division
                res += ops * k;
                op += ops;
            }
            res -= x;
        }
        
        // overflow-safe multiplication using __int128
        __int128 temp = (__int128)op * (op + 1) / 2;
        ans = (long long)(temp % mod);
        
        return (int)ans;
    }
};