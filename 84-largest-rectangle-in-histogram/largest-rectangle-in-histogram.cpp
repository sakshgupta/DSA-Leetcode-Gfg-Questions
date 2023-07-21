class Solution {
public:
    vector<int> nextSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (s.empty() == false and s.top() != -1 and arr[i] <= arr[s.top()])
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<int> prevSmaller(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (s.empty() == false and s.top() != -1 and arr[i] <= arr[s.top()])
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    int solve(vector<int> &arr){
        // idea: is to find the next smaller and prev smaller ele for each index 
        // then cal area by subtracting nextSmaller - prevSmaller - 1
        // as in area we can only include the bars which are greater than the current
        int n = arr.size();

        vector<int> next(n);
        next = nextSmaller(arr);

        vector<int> prev(n);
        prev = prevSmaller(arr);

        int area = INT_MIN;

        for(int i=0; i<n; i++){
            int length = arr[i];

            // if their is no next smaller element
            if(next[i] == -1) next[i] = n;

            int breadth = next[i] - prev[i] - 1;

            int currarea = length * (breadth);
            area = max(area, currarea);
        }

        return area;
    }

    // a bit better o(n), o(n)
    int solve_better(vector<int> &arr){
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
    int largestRectangleArea(vector<int>& heights) {
        return solve_better(heights);
    }
};