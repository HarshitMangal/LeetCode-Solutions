class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(2, INT_MAX))
        );

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // {time, x, y, state}
        // state = 0 -> next move takes 1 sec
        // state = 1 -> next move takes 2 sec
        pq.push({0, 0, 0, 0});
        dist[0][0][0] = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int x = cur[1];
            int y = cur[2];
            int state = cur[3];

            if (time > dist[x][y][state])
                continue;

            if (x == n - 1 && y == m - 1)
                return time;

            int travel = (state == 0) ? 1 : 2;
            int nextState = 1 - state;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newTime = max(time, moveTime[nx][ny]) + travel;

                    if (newTime < dist[nx][ny][nextState]) {
                        dist[nx][ny][nextState] = newTime;
                        pq.push({newTime, nx, ny, nextState});
                    }
                }
            }
        }

        return -1;
    }
};