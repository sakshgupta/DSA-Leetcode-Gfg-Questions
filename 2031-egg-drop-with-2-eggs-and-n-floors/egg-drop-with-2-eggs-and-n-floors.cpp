class Solution {
public:
    // memo
    int solve(int egg, int floor, vector<vector<int>> &dp){
        if(floor == 0 or floor == 1) return floor;
        if(egg == 1) return floor;

        if(dp[egg][floor] != -1) return dp[egg][floor];

        int ans = INT_MAX;

        for(int f = 1; f<=floor; f++){
            int ebreak = solve(egg-1, f-1, dp);
            int enotbreak = solve(egg, floor-f, dp);

            int temp = max(ebreak, enotbreak);
            ans = min(ans, temp);
        }

        return dp[egg][floor] = ans+1;
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n+1, -1));
        return solve(2, n, dp);
    }
};