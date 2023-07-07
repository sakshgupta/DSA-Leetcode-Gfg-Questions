class Solution {
public:
    int solve(vector<vector<char>> &mat, int i, int j, int &maxi, vector<vector<int>>& dp){
        if(i >= mat.size() or j >= mat[0].size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(mat, i, j+1, maxi, dp);
        int diagonal = solve(mat, i+1, j+1, maxi, dp);
        int down = solve(mat, i+1, j, maxi, dp);

        int ans = 0;
        if(mat[i][j] == '1'){
            ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
        }
        else{
            ans = 0;
        }
        return dp[i][j] = ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        solve(matrix, 0, 0, maxi, dp);
        return maxi*maxi;
    }
};