class Solution {
public:
    int longestSubarray(vector<int>& arr, int x) {
    int n = arr.size();
        int i = 0, j = 0;
        int maxlen = 0;
        pair<int, int> p = {0, 0};

        priority_queue<pair<int,int>> maxi;  // max heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mini;  // min heap

        while (j < n) {
            maxi.push({arr[j], j});
            mini.push({arr[j], j});

            // Shrink window until valid
            while (!maxi.empty() && !mini.empty() &&
                   abs(maxi.top().first - mini.top().first) > x) {
                i++;

                // Remove out-of-window elements from heaps
                while (!maxi.empty() && maxi.top().second < i) maxi.pop();
                while (!mini.empty() && mini.top().second < i) mini.pop();
            }

            // Update max length window
            if (j - i + 1 > maxlen) {
                maxlen = j - i + 1;
                p = {i, j};
            }

            j++;
        }

        return maxlen;
    }
};