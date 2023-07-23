class Solution {
public:
    bool checkValid(vector<vector<int>>& arr) {
        // just add each row and col to 2 sets and if there size == n then correct
        int n = arr.size();

        for(int i=0; i<n; i++){
            unordered_set<int> row;
            unordered_set<int> col;
            for(int j=0; j<n; j++){
                row.insert(arr[i][j]);
                col.insert(arr[j][i]);
            }
            if(row.size() != n or col.size() != n) return false;
        }
        return true;
    }
};