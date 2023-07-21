class Solution {
public:
    // this find the largest area of histogram
    int histogramArea(vector<int> &arr){
        // idea: is to find next smaller and prev smaller in one go at the same time find area
        int n = arr.size();
        stack<int> s; // this will always have the prev smaller of ith ele
        int ans = INT_MIN;

        for(int i=0; i<=n; i++){
            while(!s.empty() and (i==n or arr[i] <= arr[s.top()])){
                int curr = s.top();
                s.pop();

                // now we will find the area for the item that we popped
                // as now after popping we have its prev smaller
                // and current element i is its next smaller
                int l = arr[curr];
                int b = 0;
                if(!s.empty())
                    b = i - s.top() - 1;
                else
                    b = i - 0;

                int currarea = l*b;

                ans = max(ans, currarea);
            }

            s.push(i);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& arr) {
        // in this we go from bottom to top and keep change the matrix by adding below columns
        vector<int> hist(arr[0].size(), 0);
        int res = INT_MIN;

        for(int i=0; i<arr.size(); i++){
            // create hist array
            for(int j=0; j<arr[0].size(); j++){
                if(arr[i][j] == '1') hist[j]++;
                else hist[j] = 0;
            }
            res = max(res, histogramArea(hist));
        }

        return res;
    }
};