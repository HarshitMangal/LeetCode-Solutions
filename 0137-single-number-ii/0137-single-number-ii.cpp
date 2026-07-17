class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int ans = 0;

        // Har bit check karenge
        for (int i=0;i<32;i++) {

            int cnt = 0;

            // Sabhi numbers ki i-th bit count karo
            for (int num : nums) {

                int ithbit = (num >> i) & 1;

                if (ithbit == 1)
                    cnt++;
            }

            // Agar remainder bacha to ye unique number ki bit hai
            if (cnt % 3 != 0) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};