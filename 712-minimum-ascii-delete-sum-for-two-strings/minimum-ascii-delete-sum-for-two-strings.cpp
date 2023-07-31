class Solution {
public:
    // memo
    int solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i >= s.length() and j < p.length()){
            int temp = 0;
            for(int k = j; k<p.length(); k++){
                temp += p[k];
            }
            return temp;
        }
        if(i < s.length() and j >= p.length()){
            int temp = 0;
            for(int k = i; k<s.length(); k++){
                temp += s[k];
            }
            return temp;
        }
        if(i >= s.length() and j >= p.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = 0, op2 = 0, ans = INT_MAX;
        if(s[i] == p[j]){
            op1 = solve(s, p, i+1, j+1, dp);
        }
        else{
            op2 = min(s[i] + solve(s, p, i+1, j, dp), p[j] + solve(s, p, i, j+1, dp));
        }

        ans = min(ans, op1+op2);
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};