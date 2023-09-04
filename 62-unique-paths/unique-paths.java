public class Solution {
    public boolean isSafe(int newx, int newy, int m, int n) {
        if (newx < 0 || newx >= m || newy < 0 || newy >= n) {
            return false;
        }
        return true;
    }

    public int solve(int x, int y, int m, int n, int[][] dp) {
        if (x < 0 || y < 0 || x >= m || y >= n) {
            return 0;
        }

        if (x == m - 1 && y == n - 1) {
            return 1;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        // 2 directions
        // down
        int down = solve(x + 1, y, m, n, dp);
        // right
        int right = solve(x, y + 1, m, n, dp);

        return dp[x][y] = down + right;
    }

    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, 0, m, n, dp);
    }
}
