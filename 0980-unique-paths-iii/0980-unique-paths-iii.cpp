class Solution {
public: 
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int noofob;
    int result;

    void solve(vector<vector<int>>& mat, int i, int j, int count, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == -1) return;

        if (mat[i][j] == 2) {
            if (count == noofob) {
                result++;
            }
            return;
        }

        mat[i][j] = -1; // mark visited

        for (int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            solve(mat, newi, newj, count + 1, n, m);
        }

        mat[i][j] = 0; // backtrack
    }

    int uniquePathsIII(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int startx = -1, starty = -1;
        result = 0;
        noofob = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != -1) {  // count walkable cells (0,1,2)
                    noofob++;
                }
                if (mat[i][j] == 1) {
                    startx = i;
                    starty = j;
                }
            }
        }
        solve(mat, startx, starty, 1, n, m); // start cell already counted
        return result;
    }
};