class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // perform binary search in this 
        // if arr[i-1] < arr[i] > arr[i+1] then we found our ans
        // if arr[i-1] < arr[i] < arr[i+1] then move right
        // if arr[i-1] > arr[i] > arr[i+1] then move left
        int l = 0, h = arr.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            cout << l << " " << mid << " " << h << endl;
            if(arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1] and arr[mid] > arr[mid-1]){
                l = mid+1;
            }
            else if(arr[mid] > arr[mid+1] and arr[mid] < arr[mid-1]){
                h = mid;
            }
        }
        return -1;
    }
};