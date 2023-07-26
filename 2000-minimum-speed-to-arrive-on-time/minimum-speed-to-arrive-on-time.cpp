class Solution {
public:
    bool solve(vector<int> &dist, double hr, int idx){
        double sum = 0.0;
        for(int i=0; i<dist.size()-1; i++){
            double currtime = (double)dist[i]/idx;
            sum += ceil(currtime);
        }
        sum += (double)dist[dist.size()-1]/idx;
        cout << idx << " " << sum << endl;

        return (sum <= hr);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        int l = 1, h = 1e7;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(solve(dist, hour, mid)){
                cout << mid << endl;
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