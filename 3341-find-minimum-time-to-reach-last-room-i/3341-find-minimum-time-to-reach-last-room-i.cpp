class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        dist[0][0] = 0;

        while (!pq.empty()) {
            pair<int, pair<int, int>> front = pq.top();   // front() -> top()
            pq.pop();

            int time = front.first;
            int i = front.second.first;
            int j = front.second.second;

            if (i == n - 1 && j == m - 1)
                return time;          // cost -> time

            if (time > dist[i][j])    // cost -> time
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newcost =max(time,mat[nx][ny])+1;

                    if (newcost < dist[nx][ny]) {   // newtime -> newcost
                        dist[nx][ny] = newcost;
                        pq.push({newcost, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};