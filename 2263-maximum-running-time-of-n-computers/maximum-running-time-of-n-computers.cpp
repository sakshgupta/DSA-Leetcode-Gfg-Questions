class Solution {
public:
    bool solve(vector<int> &arr, long long time, int comp){
        // here if arr[i] > mid then just add the time
        // else we need ((all batteries left sum) / no. of computers) to determine if there sum would be able to fullfill the no. of computers
        long long ans = 0;
        for(long long i=0; i<arr.size(); i++){
            if(arr[i] > time) ans += time;
            else ans += arr[i];
        }

        return ((ans / comp) >= time); // performing avg here
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        // idea: is to perform binary search on time 
        // low = 0, and high will be sum of all battery time array
        long long l = 0, h = 0;
        
        // h = accumulate(batteries.begin(), batteries.end(), 0);

        h = 1e14;
        long long ans = 0;
        while(l<=h){
            long long mid = l + (h-l)/2;
            if(solve(batteries, mid, n)){
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        return ans;
    }
};