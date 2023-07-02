class Solution {
public:
    void solve(vector<vector<int>>& req, int idx, int curr, int &ans, vector<int> &ds){
        if(idx == req.size()){
            for(auto it: ds){
                if(it != 0){
                    return;
                }
            }

            ans = max(ans, curr);
            return;
        }

        // ignore the req
        solve(req, idx+1, curr, ans, ds);

        // include it
        ds[req[idx][0]]--;
        ds[req[idx][1]]++;
        solve(req, idx+1, curr+1, ans, ds);
        ds[req[idx][0]]++;
        ds[req[idx][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // idea: is to include a req or ignore it 
        // if include then add the dec the leave emp and add the coming one to the ds
        // if(n>requests.size())

        int ans = INT_MIN;
        vector<int> ds(n, 0);
        solve(requests, 0, 0, ans, ds);

        return ans;
    }
};