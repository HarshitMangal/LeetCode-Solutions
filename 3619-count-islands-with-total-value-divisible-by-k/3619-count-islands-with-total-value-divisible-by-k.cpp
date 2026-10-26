class Solution {
public:

    long long  dfs(vector<vector<int>>& grid, int i, int j,
            vector<vector<bool>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m ||
            visited[i][j] || grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = true;

        long long  sum = grid[i][j];

        sum += dfs(grid, i + 1, j, visited);
        sum += dfs(grid, i - 1, j, visited);
        sum += dfs(grid, i, j + 1, visited);
        sum += dfs(grid, i, j - 1, visited);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] > 0 && !visited[i][j]) {

                    long long  islandSum = dfs(grid, i, j, visited);

                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};