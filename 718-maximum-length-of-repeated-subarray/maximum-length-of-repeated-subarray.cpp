class Solution {
public:
    int solve(vector<int> &s1, vector<int> &s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        int res = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res = max(res, dp[i][j]);
                } 
                else
                    dp[i][j] = 0;
            }
        }
        
        return res;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1, nums2);
    }
};