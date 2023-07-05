class Solution {
public:
    // memo
    int solve(vector<int> &arr, int t, vector<int> &dp){
        if(t == 0) return 1;
        if(t < 0) return 0;

        if(dp[t] != -1) return dp[t];

        int takeIt = 0;
        for(int i=0; i<arr.size(); i++){
            takeIt += solve(arr, t-arr[i], dp);
        }

        return dp[t] = takeIt;
    }

    // tab
    int solve_tab(vector<int> &arr, int t){
        uint32_t* dp = new uint32_t[t+1](); // did this so as to fit 32 bit integer

        dp[0] = 1;

        for(int i=1; i<=t; i++){
            for(int j=0; j<arr.size(); j++){
                if(i - arr[j] >= 0){
                    dp[i] += dp[i - arr[j]];
                }
            }
        }

        return dp[t];
    }
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1, -1);
        return solve_tab(nums, target);
    }
};