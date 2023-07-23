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

    // tab
    long long int solve_tab(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<long long int>> dp(n+1, vector<long long int>(sum+1, -1));
        
        // base case
        for(int i=0; i<n+1; i++) dp[i][0]=1;
        for(int i=1; i<sum+1; i++) dp[0][i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]<=j) {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-coins[i-1]]);
                } 
                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }

    // space_optimization
    long long int solve_tab_space_optimization(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<long long int> curr(sum+1, -1);
        vector<long long int> prev(sum+1, -1);
        
        // base case
        prev[0] = curr[0] = 1;
        for(int i=1; i<sum+1; i++) prev[i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]<=j) {
                    curr[j]=(prev[j]+curr[j-coins[i-1]]);
                } 
                else {
                    curr[j]=prev[j];
                }
            }
            prev = curr;
        }
        
        return prev[sum];
    }

    int change(int amount, vector<int>& coins) {
        // int n = coins.size();
        // vector<vector<long long int>> dp(n+1, vector<long long int>(amount+1, -1));
        // return solve(coins, 0, amount, dp);
        
        return solve_tab_space_optimization(coins, amount);
    }
};