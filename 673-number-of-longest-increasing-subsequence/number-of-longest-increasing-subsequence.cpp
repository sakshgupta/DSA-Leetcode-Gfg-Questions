class Solution {
public:
    // int count = 0;
    // int maxlen = INT_MIN;
    // int solve(vector<int> &arr, int idx, int prev, int len){
    //     if(idx >= arr.size()) {
    //         if(maxlen <= len){
    //             maxlen = len;
    //             count++;
    //         }
    //         return 0;
    //     }

    //     int include = 0;
    //     if(prev == -1 or arr[idx] > arr[prev]){
    //         include = 1 + solve(arr, idx+1, idx, len+1);
    //     }
    //     int exclude = solve(arr, idx+1, prev, len);

    //     return max(include, exclude);
    // }

    int solve(vector<int> &arr){
        // idea: is to find prev smaller values of each ith ele and we inc the len of subsequence and when len are equal that means we need to form two subsequences ending with j and i so inc count
        // len[i] -> lenholds the len of seq.
        // count[i] -> holds the no. of seq ending with no. at ith pos

        // if smaller and there len[j]+1 > len[i] then change len[i] and change the count too
        // else if smaller and equal len then add its count to ith ele
        // then the largest len ele will have the largest count or answer
        int n = arr.size();
        
        vector<int> len(n, 1);
        vector<int> count(n, 1);

        int maxlen = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j]){
                    if(len[j] + 1 > len[i]){
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    }
                    else if(len[j] + 1 == len[i]){
                        count[i] += count[j];
                    }
                }
            }
            maxlen = max(maxlen, len[i]); // get the max len so as we can get count from it
        }

        int ans = 0;
        for(int i =0; i<n; i++){
            if(len[i] == maxlen)
                ans += count[i];
        }

        return ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        // maxlen = solve(nums, 0, -1, 0);
        // count = 0;
        // solve(nums, 0, -1, 0);
        // return count;

        return solve(nums);
    }
};