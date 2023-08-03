class Solution {
public:
    void solve(vector<int> arr, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &visited){
        if(ds.size() == arr.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<arr.size(); i++){
            if(visited[i]) continue; // if visited then don't put it again
            visited[i] = true;
            ds.push_back(arr[i]);

            solve(arr, ds, ans, visited);

            visited[i] = false; // backtrack
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // idea: is to go to start from 0 till n and keep on choosing ele if they are not there in the array already 
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(nums.size(), false); // to mark if the ele is already visited or not

        solve(nums, ds, ans, visited);

        return ans;
    }
};