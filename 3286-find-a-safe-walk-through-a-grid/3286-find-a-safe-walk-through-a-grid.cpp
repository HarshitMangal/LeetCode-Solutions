class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& mat, int health) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, -1)); // n x m hi chahiye
        queue<pair<pair<int,int>, int>> q;

        int startHealth = health - mat[0][0]; // spelling fix
        if (startHealth <= 0) return false;

        q.push({{0, 0}, startHealth});
        visited[0][0] = startHealth;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            pair<pair<int,int>, int> curr = q.front();
            q.pop();

            int x = curr.first.first;   // spelling fix: first
            int y = curr.first.second;
            int h = curr.second;

            if (x == n-1 && y == m-1) return true; // destination reached

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int nh = h - mat[nx][ny]; // new health
                    if (nh > 0 && nh > visited[nx][ny]) {
                        visited[nx][ny] = nh;
                        q.push({{nx, ny}, nh});
                    }
                }
            }
        }
        return false;
    }
};