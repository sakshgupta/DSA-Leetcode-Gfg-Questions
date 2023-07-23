class Solution {
public:
// memo
    long long int solve(vector<int>& coins, int i, int sum, vector<vector<long long int>> &dp){
        int n = coins.size();

        if(i >= n) return 0;
        if(sum < 0) return 0;
        if(sum == 0) return 1;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        long long int takeIt = solve(coins, i, sum - coins[i], dp);
        long long int leaveIt = solve(coins, i+1, sum, dp);
        
        return dp[i][sum] = takeIt+leaveIt;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long int>> dp(n+1, vector<long long int>(amount+1, -1));
        return solve(coins, 0, amount, dp);
        
        // return solve_tab(coins, amount);
    }
};