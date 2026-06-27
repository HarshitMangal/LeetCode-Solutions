/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();

        // Find Peak
        int low = 0, high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (mid + 1 < n && mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid - 1;
        }

        int peak = low;

        // Binary Search on Increasing Part
        low = 0;
        high = peak;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // Binary Search on Decreasing Part
        low = peak + 1;
        high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val > target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};