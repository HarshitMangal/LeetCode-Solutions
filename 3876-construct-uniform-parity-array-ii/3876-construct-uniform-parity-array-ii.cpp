class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        // Smallest element cannot be changed
        int parity = nums1[0] % 2;

        // Is there any smaller odd number?
        bool oddAvailable = (nums1[0] % 2 == 1);

        for (int i = 1; i < nums1.size(); i++) {

            // Already same parity -> keep it
            if (nums1[i] % 2 == parity) {
                if (nums1[i] % 2 == 1)
                    oddAvailable = true;
                continue;
            }

            // Different parity:
            // Need a smaller odd number to subtract
            if (!oddAvailable)
                return false;

            // After subtracting odd:
            // even - odd = odd
            // odd - odd = even
        }

        return true;
    }
};