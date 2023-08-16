class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> v;
        int n = arr.size();
        deque<int> dq;
        for(int i=0; i<k; i++){
            while(!dq.empty() and arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k; i<n; i++){
            v.push_back(arr[dq.front()]);
            // now is not in the current window
            while(!dq.empty() and dq.front() <= i-k){
                dq.pop_front();
            }
            // to maintain descending order
            while(!dq.empty() and arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        v.push_back(arr[dq.front()]);
        return v;
    }
};