class Solution {
public:
    void solve(vector<int> &arr, int idx, vector<vector<int>> &ans, vector<int> &ds){
        ans.push_back(ds);

        for(int i=idx; i<arr.size(); i++){
            ds.push_back(arr[i]);
            solve(arr, i+1, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums, 0, ans, ds);
        return ans;
    }
};