class Solution {
public:
    // memo
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i < 0 and j < 0) return true; // string and pat both finished
        if(i >= 0 and j < 0) return false; // string not finish, pat finished
        if(i < 0 and j >= 0) { // string finished, pat not finished
            // two case:
            // s = a b c, p = a * a b c
            for(int k = 0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            // s = a b c, p = * * a b c
            return true; 
        }

        if(dp[i][j] != -1) return dp[i][j];

        // if match or ?
        if(s[i] == p[j] or p[j] == '?') return dp[i][j] = solve(s, p, i-1, j-1, dp);
        else if(p[j] == '*'){
            // two case
            // * = empty string
            int op1 = solve(s, p, i, j-1, dp);
            // * = character/substring
            int op2 = solve(s, p, i-1, j, dp);

            return dp[i][j] = op1 or op2;
        }
        else return dp[i][j] = false; // not match
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int> (p.size()+1, -1));
        return solve(s, p, s.length()-1, p.length()-1, dp);
    }
};