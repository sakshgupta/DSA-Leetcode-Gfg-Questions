class Solution {
public:
    // memo
    double solve(int a, int b, vector<vector<double>> &dp){
        if(a <= 0 and b <= 0) return 0.5; // when both are == 0
        if(a <= 0) return 1.0; // when a == 0 and b != 0
        if(b <= 0) return 0.0; // when a != 0 and b == 0

        if(dp[a][b] != -1) return dp[a][b];

        double op1 = solve(a-100, b, dp);
        double op2 = solve(a-75, b-25, dp);
        double op3 = solve(a-50, b-50, dp);
        double op4 = solve(a-25, b-75, dp);

        return dp[a][b] = (0.25 * (op1 + op2 + op3 + op4));
    }
    double soupServings(int n) {
        // idea: is to apply 4 options in just add the base cases accordingly
        if(n >= 5000) return 1;
        vector<vector<double>> dp(n+1, vector<double> (n+1, -1));
        return solve(n, n, dp);
    }
};