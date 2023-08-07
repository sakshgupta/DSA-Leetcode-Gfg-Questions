class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // take the pointer at the 0th row and last column then if target is less then same row so move col variable
        // if target is more then move row variable
        int n = matrix.size();
        int m = matrix[0].size();
        cout << n << " " << m << endl;
        int i=0, j = m-1;
        while(i < n and j>= 0){
            if(target == matrix[i][j]) return true;
            else if(target > matrix[i][j]) i++;
            else j--;
        }
        return false;
    }
};