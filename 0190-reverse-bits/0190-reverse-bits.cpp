class Solution {
public:
    int reverseBits(int n) {
        
        int ans = 0;

        for(int i = 0; i < 32; i++) {
            int ithbit = (n >> i) & 1;
            
            ans <<= 1;
            ans = ans | ithbit;
            
            // n >>= 1;
        }

        return ans;
    }
};