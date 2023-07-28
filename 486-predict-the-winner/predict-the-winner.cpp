class Solution {
public:
    // memo
    int solve(vector<int> &arr, int i, int j, vector<vector<vector<long>>> &dp, int turn){
        if(i>j) return 0;

        if(dp[i][j][turn] != -1e10) return dp[i][j][turn];

        // when we choose for player 1 we add that to our total sum.
        if(turn == 0){
            return dp[i][j][turn] = max(arr[i] + solve(arr, i+1, j, dp, 1), 
                        arr[j] + solve(arr, i, j-1, dp, 1));
        }
        // second player chooses so we want it to be min it and dec the sum as it takes the score away from player 1
        else{ 
            return dp[i][j][turn] = min(-arr[i] + solve(arr, i+1, j, dp, 0), 
                        -arr[j] + solve(arr, i, j-1, dp, 0));
        }
    }

    // tab
    int solve_tab(vector<int> &arr){
        vector<vector<vector<long>>> dp(arr.size()+1, vector<vector<long>>(arr.size()+1, vector<long> (2, -1e10)));
        int n = arr.size();

        for(int i=n-1; i>= 0; i--){
            for(int j=i; j<n; j++){
                for(int turn = 1; turn >= 0; turn--){
                    if(i < j){
                        if(turn == 0){
                            dp[i][j][turn] = max(arr[i] + dp[i+1][j][1], arr[j] + dp[i][j-1][1]);
                        }
                        else{
                            dp[i][j][turn] = min(-arr[i] + dp[i+1][j][0], -arr[j] + dp[i][j-1][0]);
                        }
                    }
                    else dp[i][j][turn] = arr[i];
                }
            }
        }

        return dp[0][arr.size()-1][0];
    }
    bool PredictTheWinner(vector<int>& nums) {
        // vector<vector<vector<long>>> dp(nums.size()+1, vector<vector<long>>(nums.size()+1, vector<long> (2, -1e10)));
        // int ans = solve(nums, 0, nums.size()-1, dp, 0);
        int ans = solve_tab(nums);
        return ans >= 0;
    }
};