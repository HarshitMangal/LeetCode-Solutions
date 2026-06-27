class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();

        priority_queue<int> pq; // max heap

        for (int i = 0; i < n; i++) {

            vector<int> row = grid[i];

            // sort row descending
            sort(row.begin(), row.end(), greater<int>());

            // take only allowed elements from row
            for (int j = 0; j < min(limits[i], (int)row.size()); j++) {
                pq.push(row[j]);
            }
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
   }
};