class Solution {
public:
    // memo
    int solve(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp){
        if(i == arr.size()-1 and j == arr[0].size()-1) return 1;
        if(i >= arr.size() and j < arr[0].size()) return 0;
        if(i < arr.size() and j >= arr[0].size()) return 0;
        if(arr[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int sum = 0;
        if(i == arr.size()-1 or arr[i+1][j] == 1){
            sum += solve(arr, i, j+1, dp);
        }
        else if(j == arr[0].size()-1 or arr[i][j+1] == 1){
            sum += solve(arr, i+1, j, dp);
        }
        else{
            sum += solve(arr, i+1, j, dp);
            sum += solve(arr, i, j+1, dp);
        }

        return dp[i][j] = sum;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1) return 0;
        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(obstacleGrid.size()+1, (vector<int> (obstacleGrid[0].size()+1, -1)));

        return solve(obstacleGrid, 0, 0, dp);
    }
};