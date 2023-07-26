class Solution {
public:
    bool solve(vector<int> &dist, double hr, int idx){
        double sum = 0.0;
        // find sum from 0...n-2 add ceil of its
        for(int i=0; i<dist.size()-1; i++){
            double currtime = (double)dist[i]/idx;
            sum += ceil(currtime);
        } 
        // for last ele add its time rather than ceil
        sum += (double)dist[dist.size()-1]/idx;
        // cout << idx << " " << sum << endl;

        return (sum <= hr);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // apply binary search in speed as min is 1 and max is 1e7
        // then perform a check to find the sum and if its <= hour then return true
        // if true then it can be a ans but move right to find a better ans
        // if false then move left
        int ans = -1;
        int l = 1, h = 1e7;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(solve(dist, hour, mid)){
                // cout << mid << endl;
                ans = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};