class Solution {
public:
    int histogramArea(vector<int> &arr){
        int n = arr.size();

        stack<int> s; // initialize a stack to store indices
        s.push(0);
        
        int currarea, area = INT_MIN;
        
        // run the loop till n to include the rest of the pillars in the stack too
        for(int i=0; i<=n; i++){
            while(!s.empty() and (i==n or arr[s.top()] >= arr[i])){ // if the current element is less than the previous element
                int temp = s.top();
                s.pop();
                
                // calculate the area with the popped bar as the smallest bar
                currarea = arr[temp] * ((s.empty()) ? i : (i-s.top()-1));
                area = max(area, currarea);
            }
            s.push(i); // push the current index into the stack
        }
        return area;
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