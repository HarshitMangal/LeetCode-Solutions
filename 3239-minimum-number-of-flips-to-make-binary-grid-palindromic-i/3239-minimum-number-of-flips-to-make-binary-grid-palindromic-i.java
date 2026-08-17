class Solution {
    public int minFlips(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        // Rows ko palindrome banana
        int rowFlips = 0;

        for (int i = 0; i < m; i++) {

            int j = 0;
            int k = n - 1;

            while (j < k) {

                if (grid[i][j] != grid[i][k]) {
                    rowFlips++;
                }

                j++;
                k--;
            }
        }


        // Columns ko palindrome banana
        int colFlips = 0;

        for (int j = 0; j < n; j++) {

            int i = 0;
            int k = m - 1;

            while (i < k) {

                if (grid[i][j] != grid[k][j]) {
                    colFlips++;
                }

                i++;
                k--;
            }
        }

        return Math.min(rowFlips, colFlips);
    }
}