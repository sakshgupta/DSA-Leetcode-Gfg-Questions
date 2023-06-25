class Solution {
    int mod = 1e9+7;
public:
    int solve(vector<int> &loc, int start, int finish, int fuel, vector<vector<int>> &dp){
        if(fuel < 0) return 0;

        if(dp[start][fuel] != -1) return dp[start][fuel]; //memoization check

        int ans = 0;
        if(start == finish) ans++;

        // finding i
        for(int i=0; i<loc.size(); i++){
            int dis = abs(loc[i] - loc[start]);
            if(i == start or dis > fuel) continue; // base condition if i=j or if distance > fuel then just continue
            ans += solve(loc, i, finish, fuel - dis, dp);
            ans = ans % mod;
        }
        return dp[start][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // idea: is to do regular recusion firstly use loop to just find i then call recursively to find j 
        // just make sure i != j, fuel >= 0
        // if start == finish that is a valid path so do ans++
        vector<vector<int>> dp(locations.size(), vector<int>(fuel+1, -1));

        return solve(locations, start, finish, fuel, dp);
    }
};