class Solution {
public:
    // memo
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp, int turn){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // when we choose for player 1 we add that to our total sum.
        if(turn == 0){
            return max(arr[i] + solve(arr, i+1, j, dp, 1), 
                        arr[j] + solve(arr, i, j-1, dp, 1));
        }
        // second player chooses so we want it to be min it and dec the sum as it takes the score away from player 1
        else{ 
            return min(-arr[i] + solve(arr, i+1, j, dp, 0), 
                        -arr[j] + solve(arr, i, j-1, dp, 0));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        int ans = solve(nums, 0, nums.size()-1, dp, 0);
        return ans >= 0;
    }
};