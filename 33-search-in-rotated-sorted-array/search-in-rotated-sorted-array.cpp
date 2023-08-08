class Solution {
public:
    int search(vector<int>& arr, int target) {
        // idea: is to find peak then find where in the range[0, peak] or [peak+1, n] does our target lie and just perform a binary search in that range
        int l = 0, h = arr.size()-1;

        while(l<=h){
            int mid = l+(h-l)/2;
            // cout << arr[mid] << endl;

            if(arr[mid] == target) return mid;

            if(arr[l] <= arr[mid]){
                if(arr[l] <= target and target < arr[mid])
                    h = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(arr[mid] < target and target <= arr[h])
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        return -1;
    }
};