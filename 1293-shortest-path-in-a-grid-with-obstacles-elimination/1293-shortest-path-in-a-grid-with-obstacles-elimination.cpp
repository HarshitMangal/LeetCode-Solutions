class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1)
            return 0;

        vector<vector<vector<bool>>> visited(
            n,
            vector<vector<bool>>(m, vector<bool>(k + 1, false)));

        queue<pair<pair<int, int>, int>> q;

        q.push({{0, 0}, k});
        visited[0][0][k] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto curr = q.front();
                q.pop();

                int x = curr.first.first;
                int y = curr.first.second;
                int rem = curr.second;

                if (x == n - 1 && y == m - 1)
                    return steps;

                for (int i = 0; i < 4; i++) {

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;

                    // Empty cell
                    if (grid[nx][ny] == 0) {

                        if (!visited[nx][ny][rem]) {
                            visited[nx][ny][rem] = true;
                            q.push({{nx, ny}, rem});
                        }
                    }

                    // Obstacle
                    else {

                        if (rem > 0 && !visited[nx][ny][rem - 1]) {

                            visited[nx][ny][rem - 1] = true;
                            q.push({{nx, ny}, rem - 1});
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};