class Solution {
public:
    bool isSafe(int newx, int newy, int m, int n){
        if(newx < 0 or newx >= m or newy < 0 or newy >= n)
            return false;
        return true;
    }
    int solve(int x, int y, int m, int n, vector<vector<int>> &dp){
        if (x < 0 or y < 0 or x >= m or y >= n)
            return 0;
        
        if(x == m-1 and y == n-1){
            return 1;
        }

        if(dp[x][y] != -1) return dp[x][y];

        // 2 directions
        // down
        int down = solve(x+1, y, m, n, dp);
        // right
        int right = solve(x, y+1, m, n, dp);

        return dp[x][y] = down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};