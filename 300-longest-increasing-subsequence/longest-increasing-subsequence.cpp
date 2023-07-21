class Solution {
public:
    // memo
    // tc - o(n^2)
    // sc - o(n^2)
    int solve(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp){
        // base case
        if(curr >= arr.size()) return 0;

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        // include
        int include = 0;
        if(prev == -1 or arr[curr] > arr[prev]){
            include = solve(arr, curr+1, curr, dp) + 1;
        }
        // exclude
        int exclude = solve(arr, curr+1, prev, dp);

        return dp[curr][prev+1] = max(include, exclude);
    }

    // tab
    // tc - o(n^2)
    // sc - o(n^2)
    int solve_tab(vector<int> &arr){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int curr=n-1; curr>=0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){

                int include = 0;
                if(prev == -1 or arr[curr] > arr[prev])
                    include = dp[curr+1][curr + 1] + 1;
                
                int exclude = dp[curr+1][prev + 1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }

    // space optimisation
    // tc - o(n^2)
    // sc - o(2n)
    int solve_tab_space_optimised(vector<int> &arr){
        int n = arr.size();
        vector<int> next(n+1, 0), currR(n+1, 0);

        for(int curr=n-1; curr>=0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){

                int include = 0;
                if(prev == -1 or arr[curr] > arr[prev])
                    include = next[curr + 1] + 1;
                
                int exclude = next[prev + 1];

                currR[prev+1] = max(include, exclude);
            }
            next = currR;
        }

        return next[0];
    }

    // using dp with binary search
    // tc - o(nlogn)
    // sc - o(n)
    int solve_dp_binary_search(vector<int> &arr){
        // [5,8,3,7,9,1] -> [5, 8, 9], [3, 7, 9], [1, 9]
        // idea: is to make all subsets in increasing fashion 
        // [5,8] -> [3, 7, 9] -> [1, 7, 9]
        // then instead of making all subsets just make one and then 
        // that one subset wont be a correct subsequence but the len will be correct
        // if arr[i] > ans.back() then push it back
        // else find the closest largest to it and change it with that
        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1; i<n; i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                // find index of just bigger element
                auto idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[idx] = arr[i];
            }
        }

        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // check with each element to take it or not take it
        // take it only if its greater than prev element

        // int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return solve_dp_binary_search(nums);
    }
};