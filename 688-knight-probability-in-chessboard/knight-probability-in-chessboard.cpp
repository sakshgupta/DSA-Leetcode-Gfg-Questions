class Solution {
public:
    // for all the 8 dir knight can move in
    int dir[8][8] = {{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2, 1}};
    double solve(int n, int moves, int r, int c, unordered_map<string, double> &dp){
        // base cases
        if(r<0 or r>=n or c<0 or c>=n) // out of boundary
            return 0;
        if(moves == 0) return 1; // moves over but still inside

        // memo check
        string key = to_string(r) + "yo" + to_string(c) + "sup" + to_string(moves);
        if(dp.count(key)) return dp[key];

        double prob = 0.0;
        for(int i =0; i<8; i++){
            prob += (solve(n, moves-1, r+dir[i][0], c+dir[i][1], dp))/8.0;
        }

        return dp[key] = prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        // idea: is to move knight to all 8 directions and see if possible
        // for each move it makes prob to be divided by 8 (1 -> 1/8 -> 1/64 -> ...)
        // then just add all the possibilities and return 
        
        // now to make dp we can create a 3d dp but we can also do it in a unordered_map
        unordered_map<string, double> dp;
        return solve(n, k, row, column, dp);
    }
};