class Solution {
public:
    // memo
    int solve(string &s, int i, int j, vector<vector<int>> &dp){
        if(i == j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k=i; k<j; k++){
            mini = min(mini, (solve(s, i, k, dp) + solve(s, k+1, j, dp)));
        }

        if(s[i] == s[j]) mini = mini - 1; // for edge case 'aba' while adding partitions in that we won't be removing b and then checking so it will cause problem hence we need to subtract 1 if s[1] == s[j]

        return dp[i][j] = mini == INT_MAX ? -1 : mini;
    }

    // tab
    int solve_tab(string &s){
        int n = s.length();
        vector<vector<int>> dp(s.length(), vector<int> (s.length(), 1));

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(i != j){
                    int mini = INT_MAX;
                    for(int k =i; k<j; k++){
                        mini = min(mini, dp[i][k] + dp[k+1][j]);
                    }
                    if(s[i] == s[j]) mini = mini - 1;
                    dp[i][j] = mini;
                }
            }
        }

        return dp[0][n-1];
    }

    int strangePrinter(string s) {
        // idea: is to perform matrix chain multiplication and do partitions at each index then send for left and right part when i==j then ans will be 1 
        // vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
        // return solve(s, 0, s.length()-1, dp);

        return solve_tab(s);
    }
};