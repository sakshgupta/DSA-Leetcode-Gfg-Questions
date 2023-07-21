class Solution {
public:
    // memo
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i == 0 and j == 0) return true; // string and pat both finished
        if(i > 0 and j == 0) return false; // string not finish, pat finished
        if(i == 0 and j > 0) { // string finished, pat not finished
            // two case:
            // s = a b c, p = a * a b c
            for(int k = 1; k<=j; k++){
                if(p[k-1] != '*') return false;
            }
            // s = a b c, p = * * a b c
            return true; 
        }

        if(dp[i][j] != -1) return dp[i][j];

        // if match or ?
        if(s[i-1] == p[j-1] or p[j-1] == '?') return dp[i][j] = solve(s, p, i-1, j-1, dp);
        else if(p[j-1] == '*'){
            // two case
            // * = empty string
            int op1 = solve(s, p, i, j-1, dp);
            // * = character/substring
            int op2 = solve(s, p, i-1, j, dp);

            return dp[i][j] = op1 or op2;
        }
        else return dp[i][j] = false; // not match
    }

    // tab
    bool solve_tab(string &s, string &p){
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
        dp[s.size()][p.size()] = 1;
        for(int i=p.size()-1; i>=0; i--){
            if(p[i] == '*'){
                dp[s.size()][i] = dp[s.size()][i+1];
            }
            else{
                dp[s.size()][i] = 0;
            }
        }

        for(int i=s.size()-1; i>=0; i--){
            for(int j=p.size()-1; j>=0; j--){
                bool ans = 0;
                if(p[j] == '?' || s[i] == p[j]){
                    ans = dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    ans = dp[i][j+1] || dp[i+1][j];
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    // space_optimization
    bool solve_tab_space_optimization(string &s, string &p){
        vector<int> curr(p.size()+1, 0);
        vector<int> next(p.size()+1, 0);

        next[p.size()] = 1;
        for(int i=p.size()-1; i>=0; i--){
            if(p[i] == '*'){
                next[i] = next[i+1];
            }
            else{
                next[i] = 0;
            }
        }

        for(int i=s.size()-1; i>=0; i--){
            for(int j=p.size()-1; j>=0; j--){
                bool ans = 0;
                if(p[j] == '?' || s[i] == p[j]){
                    ans = next[j+1];
                }
                else if(p[j] == '*'){
                    ans = curr[j+1] || next[j];
                }

                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.size()+1, vector<int> (p.size()+1, -1));
        // return solve(s, p, s.length(), p.length(), dp);
        return solve_tab_space_optimization(s, p);
    }
};