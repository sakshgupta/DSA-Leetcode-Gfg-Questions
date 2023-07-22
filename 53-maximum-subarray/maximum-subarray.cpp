class Solution {
public:
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>> &dp) {
		// our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
        if(i >= size(A)) return mustPick ? 0 : -1e5;

        if(dp[i][mustPick] != -1) return dp[i][mustPick];

        if(mustPick)
            return dp[i][mustPick] = max(0, A[i] + solve(A, i+1, true, dp)); // either stop here or choose current element and recurse
        return dp[i][mustPick] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp)); // try both choosing current element or not choosing
    }

    // tab
    int solve_tab(vector<int>& arr) {
        vector<vector<int>> dp(2, vector<int>(size(arr)));

        dp[0][0] = dp[1][0] = arr[0];

        for(int i = 1; i < size(arr); i++) {
            dp[1][i] = max(arr[i], arr[i] + dp[1][i-1]);
            dp[0][i] = max(dp[0][i-1], dp[1][i]);
        }
        return dp[0].back();
    }

    // kadane
    int solve_kadane(vector<int>& arr) {
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : arr)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }

    int maxSubArray(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size()+1, vector<int>(3, -1));
        // return solve(nums, 0, false, dp);

        return solve_kadane(nums);
    }
};