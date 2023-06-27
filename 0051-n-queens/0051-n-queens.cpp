class Solution {
public:
    // using these 3 to store values for row, and both diagonals check
    int r[20] = {0};
    int ld[20] = {0};
    int ud[20] = {0};
    void makeSolution(vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        vector<string> temp;
        for(int i=0; i<n; i++){
            string temp1 = "";
            for(int j=0; j<n; j++){
                if(board[i][j] == 1)
                    temp1 += "Q";
                else temp1 += ".";
            }
            temp.push_back(temp1);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        // to optimize this we can use 3 arrays to store true or false for each row, and each diagonals
        
        if(r[row] == 1 or ld[row+col] == 1 or ud[n-1+col-row] == 1) return false;
        return true;

        // // first check for left row
        // int x = row, y = col;
        // while(y>=0){
        //     if(board[x][y] == 1)
        //         return false;
        //     y--;
        // }
        
        // // not checking the right row as we are going from left to right so there is no need to check for right
        // // not checking for columns as the way we are calling recursion there is no way there can be two queens in one col
        
        // // second check for top diagonal
        // x = row, y = col;
        // while(x>=0 and y>=0){
        //     if(board[x][y] == 1)
        //         return false;
        //     y--;
        //     x--;
        // }
        
        // // third check for bottom diagonal
        // x = row, y = col;
        // while(x<n and y>=0){
        //     if(board[x][y] == 1)
        //         return false;
        //     y--;
        //     x++;
        // }
        
        // // if all rows, diagonal are ok then
        // return true;
    }
    void solve(int col, vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            makeSolution(board, ans, n);
            return;
        }

        // check for each row
        for(int row = 0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                r[row] = 1;
                ld[row+col] = 1;
                ud[n-1 + col-row] = 1;

                solve(col+1, board, ans, n);

                // backtrack
                board[row][col] = 0;
                r[row] = 0;
                ld[row+col] = 0;
                ud[n-1 + col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;

        solve(0, board, ans, n);

        return ans;
    }
};