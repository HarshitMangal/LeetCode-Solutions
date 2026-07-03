class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        reverse(citations.begin(), citations.end());

        int n = citations.size();

        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (citations[mid] > mid ) {
                ans = mid;
                low = mid + 1;      // last true
            }
            else {
                high = mid - 1;
            }
        }

        return ans +1;
    }
};