class Solution {
public:
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
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
};